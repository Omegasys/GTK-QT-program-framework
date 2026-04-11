# Multi-Window Demo (GQFusion)

## Overview

This demo showcases GQFusion’s ability to run **multiple GPU-backed windows simultaneously** using a shared rendering backend.

---

## Features Demonstrated

- Multiple independent windows
- Shared GPU renderer backend
- Separate RenderTree per window
- Parallel UI rendering loops
- Cross-window GPU resource sharing (conceptual)

---

## Architecture

Window 1 → RenderTree → GPUUIRenderer → Backend  
Window 2 → RenderTree → GPUUIRenderer → Shared Backend  

---

## Running

```bash
mkdir build
cd build
cmake ..
make
./multi_window_demo

Key Idea

All windows render independently but share the same GPU context for efficiency.


---

# 🧠 What This Demo Shows

## 🪟 Multi-window architecture

```text id="mw07"
Window A → RenderTree → Renderer
Window B → RenderTree → Renderer
                     ↓
             Shared GPU Backend
