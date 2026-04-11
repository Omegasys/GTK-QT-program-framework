# Shader Compiler Tool

The **Shader Compiler** is a cross-API shader compilation tool designed for MyFramework.

It converts GLSL-like source code into an intermediate representation (IR),
applies optimizations, and outputs backend-specific shader instructions.

---

## ✨ Features

### 🧠 Shader IR System
Shaders are parsed into an intermediate representation (IR) before compilation.

### ⚡ Optimization Passes
Supports simple optimization stages such as:
- Dead instruction removal
- Instruction normalization
- Future: constant folding, SSA conversion

### 🖥 Multi-Backend Support

The compiler supports multiple rendering backends:

- 🟣 Vulkan
- 🟢 OpenGL
- 🍎 Metal

Each backend translates the same IR into platform-specific instructions.

---

## 🔄 Compilation Pipeline
GLSL Source
↓
GLSL Parser
↓
Shader IR
↓
Optimization Pass
↓
Backend Compiler
├── Vulkan
├── OpenGL
└── Metal


---

## 🚀 Usage

```bash
./shader_compiler shader.glsl
