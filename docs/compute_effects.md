# Compute Effects System

## Overview

GQFusion uses **compute shaders for all post-processing effects**.

---

## Supported Effects

### Blur
- Gaussian approximation
- UI background blur
- glass effects

### Glow
- emissive UI elements
- bloom-like expansion

### Shadow
- soft UI elevation
- depth simulation

### Redshift
- color grading
- theme transitions
- time-of-day simulation

---

## Execution Model

Input Texture  
→ Compute Shader  
→ Output Texture  
→ FrameGraph Pass

---

## Why Compute?

- Highly parallel
- Scalable across GPUs
- Flexible multi-pass pipelines
- No fragment shader limitations
