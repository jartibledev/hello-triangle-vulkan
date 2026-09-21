# Error logging
## Error: "validation layers requested, but not available!"
When I run the compilator, the message "validation layes requested, but not available!" It seems that the program can't catch the validation layers.
For the other hand, the console shows these messages: 
```text
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Users\Usuario\Desktop\projects\projects_dev\game\game_engine_exercises\Hello_triangle_vulkan\x64\Debug\Hello_triangle_vulkan.exe'. Symbols loaded.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\ntdll.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\kernel32.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Program Files\Norton\Suite\aswhook.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\KernelBase.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\user32.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\win32u.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\gdi32.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\gdi32full.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\msvcp_win.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\ucrtbase.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\shell32.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\vulkan-1.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\cfgmgr32.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\advapi32.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\msvcrt.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\sechost.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\rpcrt4.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\bcrypt.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\msvcp140d.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\vcruntime140d.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\vcruntime140_1d.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\ucrtbased.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\imm32.dll'. Symbol loading disabled by Include/Exclude setting.
The thread 13416 has exited with code 0 (0x0).
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\dinput8.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\XInput1_4.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\combase.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\devobj.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\dwmapi.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\SHCore.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\InputHost.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\oleaut32.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\WinTypes.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\CoreMessaging.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\CoreUIComponents.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\bcryptprimitives.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\propsys.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\ws2_32.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\ntmarta.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\kernel.appcore.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\kernel.appcore.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Unloaded 'C:\Windows\System32\kernel.appcore.dll'
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\uxtheme.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\msctf.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\TextInputFramework.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\dxgi.dll'. Symbol loading disabled by Include/Exclude setting.
'Hello_triangle_vulkan.exe' (Win32): Loaded 'C:\Windows\System32\Windows.StateRepositoryCore.dll'. Symbol loading disabled by Include/Exclude setting.
Exception thrown at 0x00007FFC22245369 in Hello_triangle_vulkan.exe: Microsoft C++ exception: std::runtime_error at memory location 0x0000008EF9FEF598.
The thread 17000 has exited with code 1 (0x1).
The thread 8048 has exited with code 1 (0x1).
The thread 10408 has exited with code 1 (0x1).
The thread 14156 has exited with code 1 (0x1).
The thread 11936 has exited with code 1 (0x1).
The thread 18540 has exited with code 1 (0x1).
The program '[12332] Hello_triangle_vulkan.exe' has exited with code 1 (0x1).
```
We can see two errors: 
```text
...
'Hello_triangle_vulkan.exe' (Win32): Unloaded 'C:\Windows\System32\kernel.appcore.dll'
...
Exception thrown at 0x00007FFC22245369 in Hello_triangle_vulkan.exe: Microsoft C++ exception: std::runtime_error at memory location 0x0000008EF9FEF598.
...
```
### Hyposthesis

- The first hypothesis is that the validation layers aren't configurated in the the Vulkan SD, so we have to configured it in the `Config` directory and see the `vk_layer_settings.txt` to set up the validation layers.

- Source:
Overvoorde,Alexander.2026,*Vulkan Tutorial*
- The second hypothesis is about setting the envriomental variable `VK_LAYER_PATH` into folder `Bin` in Vulkan SDK:
```text
 Tuve más o menos el mismo problema, y 
 lo arreglé configurando la variable de entorno VK_LAYER_PATH 
 a la carpeta Bin dentro del SDK de Vulkan, 
 ya que ahí estaba 
 el archivo VkLayer_khronos_validation.dll - según vkconfig, no había configurado la variable de 
 entorno VK_LAYER_PATH. Ojalá hayas cometido el mismo error que yo, y si no, ¡quizás alguien que vea este comentario sí
 lo haya hecho!

Espero que esto ayude :) 
```
Source:
[Reddit](https://www.reddit.com/r/vulkan/comments/1ckg2rc/validation_layers_requested_but_not_available/)

### Solution
The problem was a ortographic error:
```c++
//Error
const std::vector < const char*> validationLayers = {
	"VK_LAYER_HRONOS_validation"
};

//Corrected
const std::vector < const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};
```


