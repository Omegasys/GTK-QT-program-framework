# Configuration & Theming System

MyFramework provides a powerful, user-editable configuration system that enables **per-application window customization**, including:

* Time-based themes
* Multiple themes per application
* Automatic fallback handling
* Smooth blending between overlapping themes

This system is designed to give users full control over the visual behavior of applications.

---

## 📁 Config File Locations

The configuration file is stored per user:

* **Linux:** `~/.config/MyFramework/config.conf`
* **Windows:** `%APPDATA%/MyFramework/config.conf`
* **macOS:** `~/Library/Application Support/MyFramework/config.conf`

---

## 🧩 File Structure

Each application has its own section:

```ini
[Application:AppName]

fallback_theme=<theme_data>

theme_1=HH:MM-HH:MM:<theme_data>
theme_2=HH:MM-HH:MM:<theme_data>
...
```

---

## ⏱️ Time-Based Themes

Themes are activated based on time ranges:

```ini
theme_1=08:00-12:00:<theme_data>
```

### Rules

* Time format: `HH:MM` (24-hour format)
* Start time is inclusive, end time is exclusive
* Themes are evaluated using the system clock

---

## 🌈 Theme Data Format

Each theme is defined using a structured string:

```
#A-B-C-D-E-F-G-H-I-J
```

### Field Definitions

| Position | Type            | Description                         |
| -------- | --------------- | ----------------------------------- |
| A        | Hex (`#RRGGBB`) | Left window color                   |
| B        | Hex (`#RRGGBB`) | Center window color                 |
| C        | Hex (`#RRGGBB`) | Right window color                  |
| D        | Integer (0–255) | Window opacity (255 = fully opaque) |
| E        | Integer (≥0)    | Blur strength (pixels)              |
| F        | Integer (≥0)    | Corner radius (pixels)              |
| G        | Integer (≥0)    | Shadow distance (pixels)            |
| H        | Hex (`#RRGGBB`) | Shadow left color                   |
| I        | Hex (`#RRGGBB`) | Shadow center color                 |
| J        | Hex (`#RRGGBB`) | Shadow right color                  |

---

## 🧪 Example Theme

```ini
#123456-345678-56789A-255-8-12-6-000000-222222-444444
```

### Description

* Gradient window from left → right
* Fully opaque window
* Moderate blur effect
* Rounded corners
* Gradient shadow

---

## 🔄 Overlapping Themes & Blending

If two or more themes overlap in time:

```ini
theme_2=12:00-18:00:...
theme_3=17:00-22:00:...
```

### Behavior

Between **17:00–18:00**, both themes are active.

The framework will:

1. Calculate a **blend factor** based on current time
2. Interpolate all properties between themes

---

### 🧮 Blending Rules

| Property        | Method                     |
| --------------- | -------------------------- |
| Colors          | Linear interpolation (RGB) |
| Opacity         | Linear interpolation       |
| Blur            | Linear interpolation       |
| Corner radius   | Linear interpolation       |
| Shadow distance | Linear interpolation       |

---

### Result

A smooth transition between themes instead of abrupt switching.

---

## 🛡️ Fallback Theme

Each application must define a fallback:

```ini
fallback_theme=<theme_data>
```

### Used when:

* No theme matches current time
* Theme data is invalid
* Config file is missing or corrupted

---

## ⚙️ Example Configuration

```ini
[Application:MyApp]

fallback_theme=#111111-222222-333333-255-0-8-4-000000-111111-222222

theme_1=08:00-12:00:#123456-234567-345678-255-5-10-6-111111-222222-333333
theme_2=12:00-18:00:#654321-765432-876543-230-3-12-8-222222-333333-444444
theme_3=17:00-22:00:#abcdef-bcdef0-cdef01-200-6-14-10-333333-444444-555555
```

---

## ⚠️ Validation Rules

* Hex values must be valid 6-digit RGB (`#RRGGBB`)
* Numeric values must be non-negative
* Opacity must be between `0–255`

### Invalid Entries

* Ignored during parsing
* Replaced with fallback values

---

## 🔁 Live Reloading (Planned)

Future versions will support:

* Automatic config reload on file change
* Real-time theme updates without restarting apps

---

## 🧠 Internal Workflow

1. Load config file
2. Parse application section
3. Validate theme entries
4. Determine active time range
5. Blend overlapping themes (if needed)
6. Apply resulting theme to window

---

## 🔧 API Integration

### Load Configuration

```cpp
Config config;
config.load("config.conf");
```

---

### Get Active Theme

```cpp
Theme theme = config.getActiveTheme("MyApp");
```

---

### Apply Theme

```cpp
window.applyTheme(theme);
```

---

## 🚧 Future Enhancements

* Per-widget theming
* Animation curves (ease-in/out blending)
* Theme inheritance
* GUI theme editor

---

## 🎯 Design Goals

This system is designed to:

* Be **fully user-configurable**
* Support **dynamic visual changes over time**
* Provide **smooth transitions** between styles
* Remain **simple to edit manually**

---

**Result:**
A flexible and modern configuration system that enables applications to adapt visually throughout the day.
