#include <stdio.h>

/*
========================================
   COUNTY WATER BILLING SIMULATOR
========================================

Water Tariff Rates:
First 10 units: KES 25 per unit
Next 20 units:  KES 35 per unit
Above 30 units: KES 50 per unit
Fixed charge:   KES 100
*/

int main() {
    printf("========================================\n");
    printf("   COUNTY WATER BILLING SIMULATOR\n");
    printf("========================================\n\n");

    /*
    ========== CUSTOMER 1 ==========
Enter Customer ID: Enter Customer Name: Enter Previous Meter Reading: Enter Current Meter Reading: 
----------------------------------------
           CUSTOMER WATER BILL
----------------------------------------
Customer ID:       201
Customer Name:     James
Previous Reading:  12
Current Reading:   12
Units Consumed:    0
Band 1 Charge:     KES 0.00
Band 2 Charge:     KES 0.00
Band 3 Charge:     KES 0.00
Fixed Charge:      KES 100.00
TOTAL BILL:        KES 100.00
----------------------------------------

--- totalBill accumulation trace ---
After adding band1Charge: runningTotal = 0.00
After adding band2Charge: runningTotal = 0.00
After adding band3Charge: runningTotal = 0.00
After adding fixedCharge: runningTotal = 100.00
Final bill.totalBill (from calculateBill) = 100.00
-------------------------------------
Bills successfully generated: 1


========== CUSTOMER 2 ==========
Enter Customer ID: Enter Customer Name: Enter Previous Meter Reading: Enter Current Meter Reading: 
ERROR: Invalid meter reading!
Current reading cannot be less than previous reading.


========== CUSTOMER 3 ==========
Enter Customer ID: Enter Customer Name: Enter Previous Meter Reading: Enter Current Meter Reading: 
----------------------------------------
           CUSTOMER WATER BILL
----------------------------------------
Customer ID:       203
Customer Name:     Ashley
Previous Reading:  0.00
Current Reading:   0.50
Units Consumed:    0.50
Band 1 Charge:     KES 12.50
Band 2 Charge:     KES 0.00
Band 3 Charge:     KES 0.00
Fixed Charge:      KES 100.00
TOTAL BILL:        KES 112.50
----------------------------------------
Bills successfully generated: 2


========== CUSTOMER 4 ==========
Enter Customer ID: Enter Customer Name: Enter Previous Meter Reading: Enter Current Meter Reading: 
----------------------------------------
           CUSTOMER WATER BILL
----------------------------------------
Customer ID:       204
Customer Name:     Hope
Previous Reading:  15.50
Current Reading:   45.50
Units Consumed:    30.00
Band 1 Charge:     KES 250.00
Band 2 Charge:     KES 700.00
Band 3 Charge:     KES 0.00
Fixed Charge:      KES 100.00
TOTAL BILL:        KES 1050.00
----------------------------------------
Bills successfully generated: 3


========== CUSTOMER 5 ==========
Enter Customer ID: Enter Customer Name: Enter Previous Meter Reading: Enter Current Meter Reading: 
----------------------------------------
           CUSTOMER WATER BILL
----------------------------------------
Customer ID:       205
Customer Name:     John
Previous Reading:  3.00
Current Reading:   3.00
Units Consumed:    0.00
Band 1 Charge:     KES 0.00
Band 2 Charge:     KES 0.00
Band 3 Charge:     KES 0.00
Fixed Charge:      KES 100.00
TOTAL BILL:        KES 100.00
----------------------------------------
Bills successfully generated: 4


========== CUSTOMER 6 ==========
Enter Customer ID: Enter Customer Name: Enter Previous Meter Reading: Enter Current Meter Reading: 
----------------------------------------
           CUSTOMER WATER BILL
----------------------------------------
Customer ID:       206
Customer Name:     Beatrice
Previous Reading:  8.00
Current Reading:   40.00
Units Consumed:    32.00
Band 1 Charge:     KES 250.00
Band 2 Charge:     KES 700.00
Band 3 Charge:     KES 100.00
Fixed Charge:      KES 100.00
TOTAL BILL:        KES 1150.00
----------------------------------------
Bills successfully generated: 5


========================================
              FINAL SUMMARY
========================================
Total Units Consumed: 62.50
Total Revenue: KES 2512.50
Highest Consumption: 32.00 units
Invalid Records: 1
Successful Bills: 5
========================================

       L-VALUE / R-VALUE EXAMPLES

Example 1:
totalUnits = totalUnits + unitsConsumed;
L-value: totalUnits
R-value: totalUnits + unitsConsumed

Example 2:
totalRevenue = totalRevenue + bill.totalBill;
L-value: totalRevenue
R-value: totalRevenue + bill.totalBill

Example 3:
unitsConsumed = currentReading - previousReading;
L-value: unitsConsumed
R-value: currentReading - previousReading


       BINDING-TIME EXPLANATION (TASK B)

1. RATE_BAND1 (named constant)
   Type binding:    COMPILE TIME (declared 'const double')
   Storage binding: COMPILE/LOAD TIME (fixed global storage
                    reserved before main() begins)
   Value binding:   COMPILE TIME (25.0 fixed in source code,
                    can never change during execution)

2. customer.currentReading (meter reading, from cin)
   Type binding:    COMPILE TIME (declared 'double' in the
                    Customer struct)
   Storage binding: RUN TIME (a new Customer object, and
                    therefore this member, is created fresh
                    on the stack each loop iteration)
   Value binding:   RUN TIME (the actual number is unknown
                    until the user types it in via cin)

3. unitsConsumed (local variable in main)
   Type binding:    COMPILE TIME (declared 'double')
   Storage binding: RUN TIME (allocated on the stack the
                    moment its declaration executes inside
                    the for-loop body)
   Value binding:   RUN TIME (computed as currentReading -
                    previousReading, different every
                    iteration)

4. Storage address of a Customer object (variable
      'customer' declared inside the for-loop)
   Storage binding: RUN TIME. Because 'customer' is declared
                    inside the loop body, a new stack frame
                    slot is bound to it on every iteration,
                    and released when that iteration's block
                    ends. It is therefore STACK-DYNAMIC
                    storage, not static or heap storage.

Why a named constant is safer than a repeated literal:
   If the tariff for Band 1 changes, editing RATE_BAND1 in
   ONE place automatically updates every calculation that
   uses it. If '25.0' had been typed directly wherever the
   rate was needed, every occurrence would have to be found
   and edited manually, risking missed or inconsistent
   updates and making the intent of the number less clear.

      CONCEPT DEMONSTRATION NOTES

1. NAMED CONSTANTS
RATE_BAND1, RATE_BAND2, RATE_BAND3 and FIXED_CHARGE are named constants.

2. BLOCK SCOPE
bandCharge is declared inside an if/else block.
It can only be accessed inside that block.

3. STATIC LIFETIME
billCount is a static local variable.
Its scope is local to countBill(), but its lifetime continues throughout program execution.

4. NORMAL LOCAL VARIABLE
unitsConsumed is a local variable.
Its lifetime ends when its surrounding execution scope ends.

5. L-VALUE
An l-value identifies a storage location that can receive a value.

6. R-VALUE
An r-value is the value or expression evaluated and assigned to the l-value.

7. CONSTANT vs VARIABLE (TASK E NOTE)
A named constant (e.g. RATE_BAND1) is bound to its value once, at compile time, and that binding can never change for the rest of the program.
A variable (e.g. totalBill, totalRevenue) is bound to storage once, but its VALUE binding may be updated many times at run time as the program executes.


Program completed successfully.
