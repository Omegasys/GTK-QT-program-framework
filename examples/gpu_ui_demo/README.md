# GPU UI Demo (GQFusion)

## Overview

This demo showcases the **GPU-driven UI rendering system** in GQFusion.

It demonstrates:

- Widget hierarchy creation
- RenderTree virtualization
- GPUUIRenderer command generation
- Backend-agnostic rendering pipeline

---

## Architecture Flow

Widget Tree  
→ RenderTree  
→ GPUUIRenderer  
→ RendererBackend  
→ GPU

---

## Running

```bash
mkdir build
cd build
cmake ..
make
./gpu_ui_demo
Features Demonstrated
GPU-based UI rendering
Real-time render loop
Window abstraction layer
Modular rendering backend

---

# ⚙️ `demo_config.json`

```json id="ex05"
{
  "window": {
    "width": 1280,
    "height": 720,
    "title": "GQFusion GPU UI Demo",
    "vsync": true
  },

  "ui": {
    "theme": "default",
    "scale": 1.0,
    "font": "Roboto"
  },

  "rendering": {
    "framegraph": true,
    "compute_effects": false,
    "backend": "auto"
  }
}
