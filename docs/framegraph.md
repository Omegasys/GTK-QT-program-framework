# Frame Graph System

## Overview

The Frame Graph controls rendering execution as a **directed dependency graph of passes**.

---

## Structure

FrameGraph  
→ FramePasses  
→ FrameResources  
→ FrameExecutor

---

## FramePass Types

- UI Render Pass
- Compute Blur Pass
- Glow Pass
- Shadow Pass
- Final Composite Pass

---

## Execution Order

1. Build graph
2. Resolve dependencies
3. Execute passes in order
4. Present final frame

---

## Benefits

- Deterministic rendering
- Efficient resource reuse
- Easy multi-pass effects
- GPU-friendly scheduling
