# COUNTY-WATER-BILLING-SIMULATOR  and Lua assignment

Hope Mwende C026-01-0935/2025
Stacy Wanjiku C026-01-0971/2025
Ashley Moseti C026-01-0951/2025



# Assignment Documentation

## 1) Root Lua Script (Patient Workflow Simulator)

- Purpose: Demonstrates modeling independent patient workflows using Lua coroutines. Each patient is represented by a coroutine that advances through stages (Registration, Triage, Consultation, Discharge) and yields after each stage so a scheduler can decide the next patient to resume.
- Key files: main.lua (root)
- Core concepts demonstrated:
  - Cooperative concurrency with `coroutine.create`, `coroutine.resume`, `coroutine.yield`.
  - Priority-based scheduling (priority values: 1=Critical, 2=Urgent, 3=Routine).
  - Aging to prevent starvation: lowering effective priority after waiting turns.
  - Limitations: coroutines are not true parallel threads; they model cooperative multitasking only.
- How to run: install Lua (if not installed) and run:

```powershell
lua "main.lua"
```

## 2) COUNTY-WATER-BILLING-SIMULATOR

- Purpose: A small county water billing simulator that calculates customer water bills using tiered tariff bands and demonstrates basic C program concepts, program output formatting, and compile-time vs. run-time binding.
- Location: COUNTY-WATER-BILLING-SIMULATOR/
- Key files:
  - COUNTY-WATER-BILLING-SIMULATOR/main.c — simulator implementation and sample program output with labeled sections (customer billing, summaries, and concept notes).
  - COUNTY-WATER-BILLING-SIMULATOR/main.lua — a Lua file in the folder that appears to repeat the patient-coroutine material (likely included for demonstration or comparison).
  - COUNTY-WATER-BILLING-SIMULATOR/README.md — existing project README with usage or assignment notes.
- Tariff rules used (from main.c):
  - First 10 units: KES 25 per unit
  - Next 20 units: KES 35 per unit
  - Above 30 units: KES 50 per unit
  - Fixed charge: KES 100
- Features and outputs shown in `main.c`:
  - Per-customer bill with band charges, fixed charge, and total.
  - Error handling for invalid meter readings.
  - Final summary: total units, total revenue, highest consumption, invalid records, successful bills.
  - Educational notes on l-values/r-values, storage/time binding, named constants, scope, and lifetime.
- How to build and run (Windows, using gcc):

```powershell
gcc "COUNTY-WATER-BILLING-SIMULATOR\main.c" -o water_sim.exe
./water_sim.exe
```

Or with MSVC (Developer PowerShell):

```powershell
cl "COUNTY-WATER-BILLING-SIMULATOR\main.c"
main.exe
```

## Notes & Next Steps
- I created this consolidated documentation to describe both assignments and how to run them.
- If you want, I can:
  - Extract and expand the existing `COUNTY-WATER-BILLING-SIMULATOR/README.md` with the tariff and build instructions.
  - Add example input sets or unit tests for the C simulator.
  - Convert the root `main.lua` into a runnable demo script with a simple scheduler loop and sample output.

