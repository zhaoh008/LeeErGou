[Setup]
AppName=LeeErGou
AppVersion=1.0
DefaultDirName={pf}\LeeErGou
DefaultGroupName=LeeErGou
OutputDir=.\Output
OutputBaseFilename=LeeErGou_installer
Compression=lzma
SolidCompression=yes
SetupIconFile=./assets/icon/Dog.ico

[Files]
; 将可执行文件和 DLLs 添加到安装包的 bin 目录
Source: ".\cmake-build-release\install\bin\LeeErGou.exe"; DestDir: "{app}\bin"; Flags: ignoreversion
Source: ".\cmake-build-release\install\bin\*.dll"; DestDir: "{app}\bin"; Flags: ignoreversion
; 将资源文件添加到安装包的 resource 目录
Source: ".\assets\*"; DestDir: "{app}\assets"; Flags: ignoreversion recursesubdirs
Source: ".\shader\*"; DestDir: "{app}\shader"; Flags: ignoreversion recursesubdirs

[Icons]
; 在开始菜单创建快捷方式指向 bin 目录下的 EXE
Name: "{group}\LeeErGou"; Filename: "{app}\bin\LeeErGou.exe"; IconFilename: "{app}\resource\Dog.ico"
; 在桌面创建快捷方式指向 bin 目录下的 EXE
Name: "{commondesktop}\LeeErGou"; Filename: "{app}\bin\LeeErGou.exe"; IconFilename: "{app}\resource\Dog.ico"; Tasks: desktopicon
; 在应用程序的根目录创建快捷方式指向 bin 目录下的 EXE
Name: "{app}\LeeErGou"; Filename: "{app}\bin\LeeErGou.exe"; IconFilename: "{app}\resource\Dog.ico"; WorkingDir: "{app}\bin"


[Tasks]
; 用户选择是否创建桌面图标的选项
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"

[Run]
; 安装完成后，可选运行程序
Filename: "{app}\bin\LeeErGou.exe"; Description: "{cm:LaunchProgram,LeeErGou}"; Flags: nowait postinstall skipifsilent

[Languages]
Name: "chinesesimplified"; MessagesFile: "compiler:Languages\ChineseSimplified.isl"
