# Config System

The MyFramework Config System is a **live-reloading, structured configuration engine** designed for runtime updates without restarting applications.

It is deeply integrated into:

- UI system
- Theme system
- Tooling (config_editor)
- Platform layer

---

## 🔥 Core Features

- Live file watching (hot reload)
- Hierarchical config parsing
- Per-application configuration scopes
- Theme scheduling support
- Runtime updates without restart

---

## 📄 File Format

Standard config format:
window.width=1280
window.height=720
window.title=My App
theme=dark


---

## 🎨 Extended Theme Format

MyFramework supports advanced theme timeframes using this format:


#123456-123456-123456-255-255-255-255-123456-123456-123456


---

## 🧠 Field Breakdown

| Index | Meaning |
|------|--------|
| 1 | Left gradient color |
| 2 | Center gradient color |
| 3 | Right gradient color |
| 4 | Opacity (0–255) |
| 5 | Blur radius |
| 6 | Corner radius |
| 7 | Shadow distance |
| 8 | Shadow left color |
| 9 | Shadow center color |
| 10 | Shadow right color |

---

## 🔄 Live Reload System


FileSystem Watcher
↓
ConfigParser
↓
Config Update Event
↓
ThemeManager / UI System
↓
Instant UI refresh


---

## ⚠️ Rules

- Config changes must be atomic
- Invalid configs fall back to last valid state
- File watcher runs on a separate thread
