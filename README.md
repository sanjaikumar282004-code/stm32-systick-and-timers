# STM32 SysTick and Timers

## Hardware Used

- STM32F401RE Nucleo Board

## Projects Included

### 1. SYSTICK_DELAY

Generate a 1-second delay using the SysTick timer.

#### Flow Diagram

```text
System Start
      │
      ▼
Initialize UART
      │
      ▼
Enter Infinite Loop
      │
      ▼
Print "1 second delay using systick timer"
      │
      ▼
Configure SysTick for 1000 ms Delay
      │
      ▼
Wait Until COUNTFLAG Set
      │
      ▼
Return to Main Loop
```

#### Output

Output screenshot available in:

```text
SYSTICK_DELAY/Output.png
```

---

### 2. SYSTICK_INTERRUPT

Generate periodic interrupts using SysTick and toggle LD2.

#### Flow Diagram

```text
System Start
      │
      ▼
Initialize UART
      │
      ▼
Configure LD2 (PA5)
      │
      ▼
Initialize SysTick Interrupt
      │
      ▼
Main Loop Running
      │
      ├────► Print "Normal..."
      │
      ▼
SysTick Interrupt Occurs
      │
      ▼
SysTick_Handler()
      │
      ▼
Increment Tick Counter
      │
      ▼
10 Interrupts Reached?
      │
      ├── No ──► Return
      │
      └── Yes
              │
              ▼
       Toggle LD2
              │
              ▼
       Print "Interrupted..."
              │
              ▼
       Return to Main Loop
```

#### Output

Output screenshot available in:

```text
SYSTICK_INTERRUPT/Output.png
```

---

### 3. TIM2_DELAY

Generate a 1-second delay using TIM2 polling.

#### Flow Diagram

```text
System Start
      │
      ▼
Initialize UART
      │
      ▼
Initialize TIM2
      │
      ▼
Configure LD2 (PA5)
      │
      ▼
Wait for TIM2 Update Event
      │
      ▼
Overflow Occurs
      │
      ▼
Clear UIF Flag
      │
      ▼
Toggle LD2
      │
      ▼
Print "1 second is passed with timer 2"
      │
      ▼
Repeat
```

#### Output

Output screenshot available in:

```text
TIM2_DELAY/Output.png
```

---

### 4. TIM2_INTERRUPT

Generate a TIM2 interrupt every 10 seconds.

#### Flow Diagram

```text
System Start
      │
      ▼
Initialize UART
      │
      ▼
Initialize TIM2 Interrupt
      │
      ▼
Configure LD2 (PA5)
      │
      ▼
Main Loop Running
      │
      ├────► Print "Normal"
      │
      ▼
TIM2 Overflow After 10 Seconds
      │
      ▼
TIM2_IRQHandler()
      │
      ▼
Clear UIF Flag
      │
      ▼
Toggle LD2
      │
      ▼
Print "10 second is passed from tim2 interrupt"
      │
      ▼
Return to Main Loop
```

#### Output

Output screenshot available in:

```text
TIM2_INTERRUPT/Output.png
```

---

### 5. TIM2_OUTPUT_COMPARE

Use TIM2 Output Compare mode to automatically toggle LD2.

#### Flow Diagram

```text
System Start
      │
      ▼
Initialize TIM2 Output Compare Mode
      │
      ▼
Configure Output Compare Channel
      │
      ▼
Timer Counter Running
      │
      ▼
Counter Matches Compare Value
      │
      ▼
Hardware Toggles LD2
      │
      ▼
Continue Timer Operation
```

#### Output

Observed on onboard LD2 LED.

---

## Concepts Learned

- SysTick Timer
- Timer Delays
- Timer Interrupts
- Output Compare Mode
- Polling
- Interrupt Handling
- NVIC
- Register-Level Programming
