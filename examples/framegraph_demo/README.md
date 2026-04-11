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
