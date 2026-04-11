# Threading Model

## Overview

GQFusion uses a **multi-layer threading system** for UI rendering.

---

## Components

### ThreadPool
Executes low-level parallel tasks.

### JobSystem
High-level job abstraction for engine tasks.

### CommandScheduler
Batches UI draw commands in parallel.

---

## Pipeline

UI Tree  
→ JobSystem splits work  
→ ThreadPool executes tasks  
→ CommandScheduler merges results  
→ GPU submission

---

## Benefits

- Parallel UI traversal
- Reduced frame spikes
- Efficient CPU usage
- Scalable to large UIs

---

## Key Rule

GPU renders UI  
CPU only prepares data
