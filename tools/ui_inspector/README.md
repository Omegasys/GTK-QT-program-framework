# UI Inspector Tool (GQFusion)

## Overview

The UI Inspector is a developer tool for debugging GQFusion's GPU UI system.

---

## Features

- Widget hierarchy inspection
- Property editing (planned)
- Event monitoring
- Layout debugging
- Render overlay visualization

---

## Architecture

InspectorApp  
→ InspectorWindow  
→ WidgetTreeView  
→ PropertyEditor  
→ EventMonitor  
→ LayoutDebugger  
→ RenderOverlay  

---

## Resources

- inspector_theme.json → controls UI styling
- layout.json → defines panel layout

---

## Running

```bash
mkdir build
cd build
cmake ..
make
./ui_inspector
