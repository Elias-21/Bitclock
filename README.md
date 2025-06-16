# Bitclock


[German Translation (Deutsche Übersetzung)](#german-translation-deutsche-übersetzung)



A Waybar module written c to fetch and display Bitcoin stats like current highest block. 

Currently available information:
- Block heigth
- Wallet balance in BTC
- Wallet balance in Sats

More displayable information available soon.


## Installation:

The makefile was made for linux and will only work for it.
1. Download this github repo and change into it:
    ``` sh
    git clone "https://github.com/Elias-21/Bitclock.git
    cd Bitclock
    ```
2. Build it using Make:
    ``` sh
    make
    ```
3. You can install it with an example waybar config or keep your current configuration and add the module configuration yourself.
    - To install it with the example waybar configuration use this command:
    ``` sh
    make install-replace-config
    ```
    If you already have a config in `~/.config/waybar` this will replace it. if you dont have one it will just copy the example config in.
    - To keep your current configuration use his command:
    ``` sh
    make install
    ```
    This will keep you configuration. But if there are no files in `~/.config/waybar`
    it will copy the example there.

### !Make sure to set your btc address when using the Example Config!


## configuration:

Take a look at the example configuration to find all currently supported features.




## German Translation (Deutsche Übersetzung}

Ein Waybar Modul das Informationen ueber die Bitcoin Blockchain anzeigt.

Momentan verfügbare Informationen:
- Block höhe
- Wallet guthaben in BTC
- Wallet guthaben in Sats

Mehr Informationen zum anzeigen in zukunft verfügbar.


## Installation: 

Die Makefile wurde nur für Linux erstellt und funktioniert daher nur für Linux.
1. Lade dieses GitHub-Repository herunter und wechsle in das Verzeichnis:
    ``` sh
    git clone "https://github.com/Elias-21/Bitclock.git
    cd Bitclock
    ```
2. Baue das Programm mit Make:
    ``` sh
    make
    ```
3. Du kannst es mit der Beispiel Konfiguration installieren oder deine eigene Waybar Konfiguration benutzen und die Konfiguration für das modul selber schreiben.
    - Um es mit der beispiel Konfiguration zu installieren benutze diesen Befehl:
    ``` sh
    make install-replace-config
    ```
    Dies ersetzt alle Dateien im `~/.config/waybar` Verzeihchnis wenn vorhanden mit der Beispiel Konfiguration. Wenn keine Dateien dort vorhanden sind wird Beispiel Konfiguration dort trotzdem hin kopiert.
    - Um deine jetzige Konfiguration zu behalten nutze:
    ``` sh
    make install
    ```
    Wenn schon dateien in `~/.config/waybar` vorhanden sind bleiben sie dort und werden nicht ersetzt. Wenn der Ordner Leer ist wird das Beispiel dorthin kopiert.

### !Stellen sie sicher dass sie ihre BTC wallet in der config.jsonc datei angeben!


## Konfigurieren:

chauen sie sich die Beispiel Konfiguration an um alle momentan unterstützten funktionen zu sehen.
