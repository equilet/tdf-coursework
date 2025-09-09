import os

wifi_ssid = os.getenv("WIFI_SSID")
wifi_password = os.getenv("WIFI_PASSWORD")

with open("secrets.h", "w") as f:
    f.write(f'#define WIFI_SSID "{wifi_ssid}"\n')
    f.write(f'#define WIFI_PASSWORD "{wifi_password}"\n')

