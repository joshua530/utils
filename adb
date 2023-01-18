adb shell pm path <package> [ find path ]
adb shell pm list packages -f | grep <fo>
adb pull <package-path>
adb uninstall <apk>
run-as <apk>
(from within adb shell) tar -cf /data/data/<apk>/private_data.tar /data/data/<apk>/*
adb shell "run-as <apk> xxd /data/data/<apk>/private_data.tar" | xxd -r > private_data.tar
**note -> the application directories might differ for different android devices so make sure you verify then using the 'pm list packages -f' command

-- strip certificate pinning --
apk-mitm <path to pulled apk>
-> apk-mitm will install apktool & uber-apk-signer, no need to manually install them if this is all you need them for
-> apk-mitm will remove certificate pinning, self sign, and build the application, just run the command above

-- after modifying android apk, make sure to sign it --
keytool -genkeypair -v -keystore resign.keystore -alias alias_name -keyalg RSA -keysize 2048 -validity 10000

-- decompress and compress jar --
apktool d -o outdir <apk path>
edit AndroidManifext.xml add android:debuggable="true" to <application> tag
<generate keystore using command above>
apktool b -o <apkname>.apk <decompiled apk folder>
uber-apk-signer -a <apk path> -ks <created keystore>
