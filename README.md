# Hello_triangle_vulkan
## Instancia
### Creando la instancia
La instancia es el enlace entre tu aplicación y la librería de Vulkan. Lo primero será llamar a `createInstance()` desde `initVulkan()`.

```c++
void initVulkan(){
	createInstance();
}
```
Luego añadimos un miembro que albergará el *handle* de la instancia:
```c++
VkInstance instance;
```

En la definición del método `createInstance` rellenamos un *struct* con datos que otorgan información al *driver* para optimizar nuestra aplicación.

```c++
void createInstance() {
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Hello Triangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;
```
Añadimos otro *struct* que le dice al *driver* qué extensiones globales y capas de validación queremos usar:
```c++
VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;

		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;
		createInfo.enabledLayerCount = 0;
```
Las dos primeras líneas inicializan el struct. Las variables `glfwExtensionCount` y `glfwExtensions` especifican las extensiones globales
deseadas para que Vulkan pueda crear una interfaz con el sistema de gestión de ventanas. El parámetro `enabledLayerCount` especifica el número de capas de validación disponibles.

Ahora podemos llamar a `vkCreateInstance`:

```c++
VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
```

Para asegurarnos de si la isntance fue creada correctamente, solo tenemos que revisar el valor de éxito devuelto:

```c++
if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
			throw std::runtime_error("failed to create instance!");
		}
```
Todas las funciones en Vulkan devuelven un valor de tipo `VkResult` llamado `VK_SUCCESS` o un código de error.   

### El *checking* para soporte de extenciones

A veces Vulkan nos devuelve un `VK_ERROR_EXTENSION_NOT_PRESENT`, por lo que o bien especificamos que extensiones queremos usar 
o creamos una función que recoga todas las extensiones disponibles. Para este propósito usaremos `vkEnumerateInstanceExtensionProperties`,
que recoge una lista de extensiones con soporte ante de crear la instancia. Coge un puntero que almacena
el número de extenciones y un *array* de `VkExtensionProperties` para almacenar los detalles de las extensiones
También obtiene el primer parámetro que nos permite filtrar extensiones con una especifica capa de validación.

Necesitamos conocer cuántas extensiones hay alojadas en un *array* para conseguir los detalles de las extensiones.

```c++
uint32_t extensionCount = 0;
vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
```
Alojamos un *array* para almacenar los detalles de las extensiones:
```c++
std::vector <VkExtensionProperties> extensions(extensionCount);
```
Para usar `vector` en nuestro código deberemos añadir un `include` al principio de nuestro código:
```c++
#include <vector>
```
Pedimos los detalles de las extensiones:
```c++
vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
```
Cada *struct* `VkExtensionProperties` contiene el nombre y la version de una extension:
```c++
std::cout << "available extension:\n ";

		for (const auto& extension : extensions) {
			std::cout << '\t' << extension.extensionName << '\n';
		}
```
### Limpieza final
`VkInstance` debería ser limpiada justo antes de que el programa comienze a existir:
```c++
void cleanup() {
		vkDestroyInstance(instance, nullptr);
		glfwDestroyWindow(window);
		glfwTerminate();
	}
```

Si corres el programa te tiene que aparecer algo como esto: 
<img src="./multimedia/pictures/extension_support.webp" alt="Banner del Proyecto" width="600px" />

## Validation Layers
El debug son bloques de código que se encargan de avisarnos cuando hay un error en el programa.
Las *validation layers* son componentes que tienen *hooks* (métodos abiertos que pueden ser escritos por las subclases) dentro de las llamadas
a las funciones de vulkan para aplicar operaciones adicionales en el caso de llamada.
### Using validation layers
Para activar las *validation layers* necesitamos especificar su nombre. Todas las *validation layers*
están en `VK_LAYER_KHRONOS_validation`.

```c++
const std::vector < const char*> validationLayers = {
	"VK_LAYER_HRONOS_validation"
};

#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else 
	const bool enableValidationLayers = true;
#endif
```
Añadimos una nueva función `checkValidationSupport` que checkea si todas las respuestas están disponibles.
Primero crea una lista de todas las capas disponibles usando `vkEnumerateLayerProperties`.
```c++
bool checkValidationLayerSupport() {
		uint32_t layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

		std::vector<VkLayerProperties> availablelayers(layerCount);

		vkEnumerateInstanceLayerProperties(&layerCount, availablelayers.data());

		 return false;
}
```
El siguiente paso es revisar si todas las capas en `validationlayers` existen en la lista de `avilableLayers`. Podrías necesitar 
incluir `<cstring>` para `strcmp` .
```c++
for (const char* layerName : validationLayers) {
			bool layerFound = false;

			for (const auto& layerProperties : availablelayers) {
				if (strcmp(layerName, layerProperties.layerName) == 0) {
					layerFound = true;
					break;
				}
			}
			if (!layerFound) {
				return false;
			}
		}

		return true;
}
```

Implementamos esta función en `createInstance`:
```c++
void createInstance() {
		if (enableValidationLayers && !checkValidationLayerSupport()) {
			throw std::runtime_error("validation layers requested, but not available!");
		}
		...
}
```
Finalmente, mdoificamos el  struct `VkInstanceCreateInfo` para incluir los nombres de las *validation layers* si están disponibles:
```c++
if (enableValidationLayers) {
			createInfo.enabledLayerCount = static_cast <uint32_t>(validationLayers.size());
			createInfo.ppEnabledLayerNames = validationLayers.data();
		}
		else {
			createInfo.enabledLayerCount = 0;
}
```

### Message Callback
Las *validation layer* imprimen mensajes de *debug* estándar por defecto, pero podemos también configurarlas por nuestra cuenta 
creando un *callback* explícito en nuestro programa, lo que nos permitirá decidir que tipo de mensajes nos gustaría ver, 
ya que todos no son necesariamente errores fatales.

Con la extensión `VK_EXT_debug_utils` nos permitirá montar un *callback* een el programa para manejar los mensajes y obtener los detalles asociados.

Creamos la función `getRequiredExtensions`:
```c++
std::vector<const char*> getRequiredExtensions() {
		uint32_t glfwExtensionsCount = 0;
		const char** glfwExtensions = 0;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionsCount);

		std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionsCount);

		if (enableValidationLayers) {
			extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
		}
		return extensions;
	}
```
Devolverá una lista de extensiones basada en cualquier *validation_layer*, esté disponible o no.


