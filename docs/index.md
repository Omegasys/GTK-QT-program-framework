# MyFramework Documentation

Welcome to **MyFramework** — a modern, 64-bit-only GUI framework designed for performance, flexibility, and dynamic user experiences.

---

## 🚀 Overview

MyFramework combines the best ideas from traditional GUI toolkits while introducing a powerful **time-based theming and live configuration system**.

It is built to be:

* Lightweight
* Cross-platform
* Fully customizable
* Future-focused

---

## ✨ Key Features

### 🧩 Core UI System

* Windows, widgets, layouts, and containers
* Extensible widget architecture
* Custom rendering support

---

### 🔔 Event System

* Signal/slot-style communication
* Type-safe callbacks
* Designed for asynchronous expansion

---

### 🎨 Advanced Theming Engine

A powerful and unique system that allows:

* Per-application themes
* Multiple themes per app
* Time-based theme switching
* Smooth blending between overlapping themes
* Gradient-based window and shadow styling

---

### 🔄 Live Reload System

No restarts required.

* Automatically detects `.config` file changes
* Reloads configuration in real time
* Instantly updates application appearance
* Designed for rapid iteration and customization

---

### 🌍 Cross-Platform Support

* Linux
* Windows
* macOS

Unified API across all platforms.

---

### ⚡ 64-Bit Only

* Built exclusively for modern systems
* No legacy 32-bit support
* Optimized for performance and memory usage

---

## 🏗️ Architecture

````
Application Layer
    ↓
UI Layer (Widgets, Layouts)
    ↓
Core Systems (Signals, Events)
    ↓
Theming System (Config + Scheduler + Blender + Live Reload)
    ↓
Platform Abstraction Layer
    ↓
Operating System
``` id="l6q2m9"

---

## 🎨 Configuration System

MyFramework uses a user-editable configuration file:

```ini id="h4rwvj"
[Application:MyApp]

fallback_theme=#111111-222222-333333-255-0-8-4-000000-111111-222222

theme_1=08:00-12:00:#123456-234567-345678-255-5-10-6-111111-222222-333333
theme_2=12:00-18:00:#654321-765432-876543-230-3-12-8-222222-333333-444444
theme_3=17:00-22:00:#abcdef-bcdef0-cdef01-200-6-14-10-333333-444444-555555
````

### Features

* Time-based activation
* Automatic fallback handling
* Smooth transitions between overlapping themes

See: `config_system.md` for full details.

---

## 🔄 Live Reload Example

1. Open your config file
2. Modify a theme value
3. Save the file

➡️ The application updates instantly without restarting.

---

## 📦 Installation

### Requirements

* 64-bit CPU (x86_64 or ARM64)
* CMake ≥ 3.16
* C++17 compatible compiler

---

### Build

```bash
git clone https://github.com/yourusername/MyFramework.git
cd MyFramework
mkdir build && cd build
cmake ..
make
```

---

## 🧪 Running Examples

```bash
./bin/basic_app
./bin/themed_app
```

---

## 📚 Documentation Structure

* `api_reference.md` — API details
* `config_system.md` — Config + theming system
* `tutorials.md` — Step-by-step guides
* `examples/` — Practical usage

---

## 🛠️ Basic Example

```cpp id="0b3gmb"
#include <MyFramework/Application.h>
#include <MyFramework/Window.h>
#include <MyFramework/Button.h>

int main() {
    MyFramework::Application app;

    MyFramework::Window window("Hello", 800, 600);

    MyFramework::Button button("Click Me");
    button.onClick([]() {
        printf("Clicked!\n");
    });

    window.setCentralWidget(&button);
    window.show();

    return app.run();
}
```

---

## 🧭 Roadmap

* [ ] Declarative UI system (QML-like)
* [ ] GPU-accelerated rendering
* [ ] Animated theme transitions
* [ ] Per-widget theming
* [ ] Live UI editor

---

## 🤝 Contributing

1. Fork the repository
2. Create a branch
3. Submit a pull request

---

## 🔒 License

Licensed under the **GNU General Public License (GPL)**.

---

## 🧠 Philosophy

MyFramework is built on three principles:

* **Control** — Users should fully control appearance
* **Performance** — No unnecessary overhead
* **Simplicity** — Powerful features without complexity

---

## 📬 Support

* Open an issue on GitHub
* Start a discussion

---

**Build dynamic applications. Customize everything. No compromises.**
