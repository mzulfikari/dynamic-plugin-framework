# 🚀 Dynamic Plugin Framework

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-20-blue.svg" />
  <img src="https://img.shields.io/badge/CMake-Build-green.svg" />
  <img src="https://img.shields.io/badge/Architecture-Plugin%20Based-purple.svg" />
  <img src="https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey.svg" />
  <img src="https://img.shields.io/badge/Status-Active-brightgreen.svg" />
</p>

---

## 📌 Overview

Dynamic Plugin Framework is a modern C++20-based modular system designed for dynamic loading and execution of plugins at runtime.

It enables building extensible systems such as game engines, automation tools, runtime command systems, and scalable backend services.

---

## 📁 Project Structure

<p align="center">
  <img src="docs/Folder%20Structure.png" width="900"/>
</p>

---

## ⚙️ Features

- 🔌 Hot plugin loading (runtime DLL loading)
- 🧩 Modular command system
- ⚡ Lightweight runtime core
- 🔄 Dynamic command registration
- 🪟 Windows API support
- 🧠 Extensible architecture

---



## 🚀 How It Works

1. Host application starts runtime
2. PluginLoader loads dynamic libraries
3. Plugins register commands
4. Commands are stored in registry
5. Runtime executes commands on demand

---

## 🧩 Example

```cpp
registerCommand("add", [](int a, int b) {
    return a + b;
});
```

```cpp
execute("add", 5, 3); // 8
```

---

## 🔧 Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

---

## 🧪 Example Commands

```
add 10 20   -> 30
sub 50 10   -> 40
mul 3 4     -> 12
sqrt 16     -> 4
```

---

## 🧠 Philosophy

Everything is a plugin. Nothing is hardcoded.

---

## 📌 Roadmap

- Linux support (.so)
- Async execution system
- Plugin sandboxing
- Remote plugin loading
- GUI plugin manager

---

## 🏁 Status

Core system is stable. Plugin system is actively expanding.

---


## 📄 License

MIT License © 2026

---

## 👨‍💻 Author

Developed as a software architecture learning project focused on modular and extensible system design.
