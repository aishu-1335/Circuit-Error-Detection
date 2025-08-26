# ⚡ Circuit Error Detection

  This project is a simple tool written in C to model circuits as graphs and check for structural errors in their connections. Each component is represented as a node, and each connection between components is represented as an edge.

---

## ✨ Features
- Models circuits using adjacency lists.  
- Allows adding connections between components.  
- Detects errors such as:  
  - 🔄 Self-connections (a component connected to itself).  
  - ⚠️ Invalid number of components.  
  - 🔌 Incorrect number of connections for certain nodes.  
- Manages memory efficiently by freeing all allocations.  

---

## 🔍 How It Works
1. The user specifies the number of components in the circuit.  
2. The number of connections and the connected components are entered.  
3. The program builds the circuit representation.  
4. Error detection is performed to ensure the circuit is valid.  
5. The result is displayed as either an error message or a confirmation that no errors exist.  

---

## ✅ Example Outcomes
- **Valid Circuit** → The program confirms no errors.  
- **Invalid Circuit** → The program highlights an error in the structure (like self-loops or incorrect connections).  

---

## 📖 Key Concepts
- Graph representation of circuits.  
- Use of linked lists for adjacency.  
- Basic error detection in circuit design.  
- Dynamic memory allocation and cleanup.  

---

## 🚀 Future Enhancements
- Detect open circuits where some components are unconnected.  
- Identify short circuits caused by multiple incorrect links.  
- Provide a clearer explanation of the type of error.  
- Add visualization of the circuit structure.  

---
