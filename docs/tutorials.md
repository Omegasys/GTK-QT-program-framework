# MyFramework Tutorials

This guide walks you through building applications with **MyFramework**, from a simple window to advanced features like **time-based theming and live config reload**.

---

## 🚀 Tutorial 1: Your First Application

### Goal

Create a simple window with a button.

---

### Step 1: Create a File

```cpp
// main.cpp
#include <MyFramework/Application.h>
#include <MyFramework/Window.h>
#include <MyFramework/Button.h>

using namespace MyFramework;

int main() {
    Application app;

    Window window("Hello MyFramework", 800, 600);

    Button button("Click Me");
    button.onClick([]() {
        printf("Button clicked!\n");
    });

    window.setCentralWidget(&button);
    window.show();

    return app.run();
}
```

---

### Step 2: Build

```bash
mkdir build && cd build
cmake ..
make
```

---

### Result

A window appears with a clickable button.

---

## 🧩 Tutorial 2: Using Layouts

### Goal

Arrange multiple widgets.

---

```cpp
#include <MyFramework/Layouts.h>

VBoxLayout layout;

Button btn1("Button 1");
Button btn2("Button 2");

layout.addWidget(&btn1);
layout.addWidget(&btn2);

window.setCentralWidget(&layout);
```

---

### Result

Buttons are stacked vertically.

---

## 🔔 Tutorial 3: Signals & Events

### Goal

React to user input.

---

```cpp
Button button("Press Me");

button.onClick([]() {
    printf("Pressed!\n");
});
```

---

### Advanced Example

```cpp
Signal<int> valueChanged;

valueChanged.connect([](int v) {
    printf("Value: %d\n", v);
});

valueChanged.emit(42);
```

---

## 🎨 Tutorial 4: Applying a Theme

### Goal

Manually apply a theme to a window.

---

```cpp
#include <MyFramework/theme/Theme.h>

Theme theme;

theme.windowLeft   = Color(20, 20, 20);
theme.windowCenter = Color(40, 40, 40);
theme.windowRight  = Color(60, 60, 60);

theme.opacity = 255;
theme.blur = 5;
theme.cornerRadius = 10;
theme.shadowDistance = 6;

theme.shadowLeft   = Color(0, 0, 0);
theme.shadowCenter = Color(20, 20, 20);
theme.shadowRight  = Color(40, 40, 40);

window.applyTheme(theme);
```

---

## ⚙️ Tutorial 5: Using the Config System

### Goal

Load themes from a config file.

---

### Step 1: Create `config.conf`

```ini
[Application:MyApp]

fallback_theme=#111111-222222-333333-255-0-8-4-000000-111111-222222

theme_1=08:00-18:00:#123456-234567-345678-255-5-10-6-111111-222222-333333
```

---

### Step 2: Load Config

```cpp
#include <MyFramework/config/ConfigParser.h>

Config config = ConfigParser::parse("config.conf");

Theme theme = config.apps["MyApp"].fallback;

window.applyTheme(theme);
```

---

## ⏱️ Tutorial 6: Time-Based Themes

### Goal

Automatically switch themes based on time.

---

```cpp
#include <MyFramework/theme/ThemeScheduler.h>

std::string currentTime = "14:30";

Theme theme = ThemeScheduler::resolveTheme(
    config.apps["MyApp"].themes,
    config.apps["MyApp"].fallback,
    currentTime
);

window.applyTheme(theme);
```

---

### Result

Theme changes depending on time of day.

---

## 🔄 Tutorial 7: Live Reload (Real-Time Updates)

### Goal

Update UI instantly when config changes.

---

### Step 1: Setup Watcher

```cpp
#include <MyFramework/config/ConfigWatcher.h>

ConfigWatcher watcher("config.conf");

watcher.start([&]() {
    Config config = ConfigParser::parse("config.conf");

    std::string now = "14:30"; // replace with real time

    Theme theme = ThemeScheduler::resolveTheme(
        config.apps["MyApp"].themes,
        config.apps["MyApp"].fallback,
        now
    );

    window.applyTheme(theme);
});
```

---

### Step 2: Edit Config File

Change:

```ini
theme_1=08:00-18:00:#FF0000-FF0000-FF0000-255-0-0-0-000000-000000-000000
```

---

### Result

The window updates instantly—no restart needed.

---

## 🌈 Tutorial 8: Theme Blending

### Goal

Create smooth transitions between themes.

---

### Config Example

```ini
theme_1=12:00-18:00:#0000FF-0000FF-0000FF-255-0-0-0-000000-000000-000000
theme_2=17:00-22:00:#FF0000-FF0000-FF0000-255-0-0-0-000000-000000-000000
```

---

### Result

From **17:00–18:00**, the window gradually transitions from blue → red.

---

## 🧪 Tutorial 9: Full Example (Putting It All Together)

```cpp
Application app;
Window window("Themed App", 800, 600);

ConfigWatcher watcher("config.conf");

watcher.start([&]() {
    Config config = ConfigParser::parse("config.conf");

    std::string now = "14:30";

    Theme theme = ThemeScheduler::resolveTheme(
        config.apps["ThemedApp"].themes,
        config.apps["ThemedApp"].fallback,
        now
    );

    window.applyTheme(theme);
});

window.show();
return app.run();
```

---

## ⚠️ Common Mistakes

### ❌ Invalid Theme Format

```ini
#12345   ← wrong
```

### ✅ Correct

```ini
#123456
```

---

### ❌ Missing fallback

Always define:

```ini
fallback_theme=...
```

---

### ❌ Wrong time format

```ini
8:00   ← wrong
```

### ✅ Correct

```ini
08:00
```

---

## 🧭 Next Steps

* Explore `api_reference.md` for full API details
* Modify themes to experiment with UI behavior
* Try creating your own widgets

---

## 🧠 Tips

* Start simple, then add theming
* Use live reload for fast iteration
* Keep configs readable and organized

---

**You’re now ready to build dynamic, customizable GUI applications with MyFramework.**
