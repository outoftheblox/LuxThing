# LuxThing
A lux sensor based on the MAX44009 which communicates over secure MQTT.

# Settings
See https://github.com/outoftheblox/ThingSettings

# Deploy
```
pio run -e d1_mini --upload-port /dev/ttyUSB0
```

# Debug
```
pio device monitor -e d1_mini --port /dev/ttyUSB0
```
