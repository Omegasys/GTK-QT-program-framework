# FrameGraph Debugger (GQFusion)

## Overview

The FrameGraph Debugger is a visual tool for inspecting the rendering pipeline.

It allows developers to understand:

- Pass dependencies
- Resource flow
- Execution order
- GPU pipeline structure

---

## Features

- Node-based graph visualization
- Pass inspection panel
- Resource tracking
- Execution timeline view

---

## UI Layout

GraphCanvas (main view)  
→ PassInspector  
→ ResourceTracker  
→ ExecutionTimeline  

---

## Running

```bash
mkdir build
cd build
cmake ..
make
./framegraph_debugger
