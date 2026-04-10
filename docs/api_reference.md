# MyFramework API Reference

This document provides a detailed reference for the public API of **MyFramework**.

---

## 📦 Namespace

All classes and functions are contained within:

```cpp
namespace MyFramework { }
```

---

## 🧠 Core Classes

---

### Application

Manages the application lifecycle and event loop.

```cpp
class Application {
public:
    Application();
    ~Application();

    int run();
    void quit();
};
```

#### Methods

* `int run()`
  Starts the main event loop.

* `void quit()`
  Stops the application.

---

### Window

Represents a top-level application window.

```cpp
class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    void show();
    void hide();

    void setTitle(const std::string& title);
    void setSize(int width, int height);

    void setCentralWidget(Widget* widget);

    void applyTheme(const Theme& theme);
};
```

#### Methods

* `show()` — Display window
* `hide()` — Hide window
* `setTitle()` — Change title
* `setSize()` — Resize window
* `setCentralWidget()` — Set main widget
* `applyTheme()` — Apply a theme to the window

---

### Widget

Base class for all UI elements.

```cpp
class Widget {
public:
    Widget();
    virtual ~Widget();

    void show();
    void hide();

    void setParent(Widget* parent);
    Widget* parent() const;

    void setPosition(int x, int y);
    void setSize(int width, int height);

protected:
    virtual void paint();
};
```

---

### Button

Clickable UI element.

```cpp
class Button : public Widget {
public:
    Button(const std::string& text);

    void setText(const std::string& text);
    std::string text() const;

    void onClick(std::function<void()> callback);
};
```

---

### Layout System

#### Base Layout

```cpp
class Layout {
public:
    virtual ~Layout();
    virtual void addWidget(Widget* widget) = 0;
};
```

#### VBoxLayout

```cpp
class VBoxLayout : public Layout {
public:
    void addWidget(Widget* widget) override;
};
```

#### HBoxLayout

```cpp
class HBoxLayout : public Layout {
public:
    void addWidget(Widget* widget) override;
};
```

---

## 🔔 Signals System

```cpp
template<typename... Args>
class Signal {
public:
    void connect(std::function<void(Args...)> slot);
    void emit(Args... args);
};
```

---

## 🎨 Theming System

---

### Theme Structure

```cpp
struct Theme {
    Color windowLeft;
    Color windowCenter;
    Color windowRight;

    int opacity;
    int blur;
    int cornerRadius;
    int shadowDistance;

    Color shadowLeft;
    Color shadowCenter;
    Color shadowRight;
};
```

---

### Color

```cpp
struct Color {
    int r, g, b;

    Color(int r, int g, int b);
    static Color fromHex(const std::string& hex);
};
```

---

## 🔄 Theme Blending

---

### ThemeBlender

```cpp
class ThemeBlender {
public:
    static Theme blend(const Theme& a, const Theme& b, float t);
};
```

#### Description

Blends two themes using linear interpolation.

* `t = 0.0` → Theme A
* `t = 1.0` → Theme B

---

## ⏱️ Theme Scheduling

---

### ThemeEntry

```cpp
struct ThemeEntry {
    std::string start;
    std::string end;
    Theme theme;
};
```

---

### ThemeScheduler

```cpp
class ThemeScheduler {
public:
    static Theme resolveTheme(
        const std::vector<ThemeEntry>& themes,
        const Theme& fallback,
        const std::string& currentTime
    );
};
```

#### Description

* Selects active themes based on time
* Handles overlapping ranges
* Uses `ThemeBlender` when needed
* Falls back if no theme matches

---

## ⚙️ Configuration System

---

### Config Structures

```cpp
struct AppConfig {
    Theme fallback;
    std::vector<ThemeEntry> themes;
};

struct Config {
    std::unordered_map<std::string, AppConfig> apps;
};
```

---

### ConfigParser

```cpp
class ConfigParser {
public:
    static Config parse(const std::string& path);
};
```

#### Description

* Reads `.conf` files
* Parses applications and themes
* Validates format
* Builds runtime config objects

---

## 🔄 Live Reload System

---

### ConfigWatcher

```cpp
class ConfigWatcher {
public:
    ConfigWatcher(const std::string& path);

    void start(std::function<void()> onChange);
    void stop();
};
```

#### Description

* Monitors config file for changes
* Triggers callback on modification
* Uses polling (default ~500ms interval)

---

## 🔗 Example Integration

```cpp
Config config = ConfigParser::parse("config.conf");

Theme theme = ThemeScheduler::resolveTheme(
    config.apps["MyApp"].themes,
    config.apps["MyApp"].fallback,
    "14:30"
);

window.applyTheme(theme);
```

---

## ⚠️ Error Handling

* Invalid config entries are ignored
* Fallback theme is used when needed
* Exceptions may be thrown for critical errors

---

## 📌 Constraints

* 64-bit systems only
* Time format must be `"HH:MM"`
* Hex colors must be `#RRGGBB`

---

## 🚧 Experimental APIs

* Rendering system
* Declarative UI (planned)
* Animation engine

---

## 📚 Related Documentation

* `config_system.md` — full config format
* `index.md` — overview and architecture
* `tutorials.md` — usage guides

---

## 🧠 Design Notes

This API is designed to:

* Be simple and consistent
* Provide powerful customization
* Support dynamic runtime behavior

---

**End of API Reference**
