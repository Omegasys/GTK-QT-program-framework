# FrameGraph Demo (GQFusion)

## Overview

This demo shows how GQFusion executes rendering using a **Frame Graph system**.

It demonstrates:

- Multi-pass rendering
- Resource dependency tracking
- Compute + UI pipeline chaining
- Frame execution orchestration

---

## Pipeline

UI Pass  
→ Blur Pass  
→ Glow Pass  
→ Composite Pass  
→ Final Output

---

## Running

```bash
mkdir build
cd build
cmake ..
make
./framegraph_demo
Key Idea

All rendering is structured as a dependency graph of passes, not a linear pipeline.


---

# 🌊 `framegraph_visual.json`

```json id="fgd05"
{
  "framegraph": {
    "name": "UI_PostFX_Graph",

    "passes": [
      "ui_pass",
      "blur_pass",
      "glow_pass",
      "composite_pass"
    ],

    "execution_order": [
      "ui_pass",
      "blur_pass",
      "glow_pass",
      "composite_pass"
    ],

    "resources": [
      "ui_buffer",
      "blur_buffer",
      "glow_buffer",
      "final_output"
    ]
  }
}
