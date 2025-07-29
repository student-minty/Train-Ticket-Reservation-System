# Train Ticket Reservation System

A **C-based console application** for railway ticket booking.  
It allows users to book train tickets between multiple locations, choose travel classes, select berths, order food, and print receipts.  
Includes basic functionality for ticket cancellation with refund calculation.

---

## Team Members
- **Isha Jaiswal** – 2201CS32  
- **Janvi Kumari** – 2201CE24  
- **Sravani** – 2201CE28  
- **Chanchal Tolani** – 2201PH09  
- **Diksha Talukdar** – 2201CB23  
- **Mounika** – 2201EE35  
- **Kavya Shree** – 2201CS37  
- **Rajesh** – 2201CB36  

---

## Features
- **Multiple Routes**: Book tickets for several predefined source-destination pairs (e.g., Delhi–Chennai, Mumbai–Kolkata).  
- **Train Selection**: Choose between **Rajdhani Express** and **Duronto Express** for each route.  
- **Class & Berth Options**:
  - Sleeper  
  - 1st, 2nd, and 3rd AC Classes  
  - Upper, Lower, Middle, Side Berths  
- **Food Ordering**: Optional food selection (Veg/Non-Veg Thali).  
- **GST Calculation**: Automatically adds 18% GST to ticket price.  
- **Ticket Cancellation**: Refund with 10% deduction.  
- **Receipt Generation**: Prints detailed passenger and payment info.

---

## Example Workflow
Welcome to Railway Ticket Reservation
Select the source and Destination
Press 1 for Delhi to Chennai
Press 2 for Delhi to Kolkata
Press 3 for Kolkata to Chennai
Press 4 for Delhi to Mumbai
Press 5 for Mumbai to Chennai
Press 6 for Mumbai to Kolkata
Enter your choice: 1

Press 1 for Rajdhani express departs at 12:40 p.m
Press 2 for Duronto express departs at 11:20 p.m
Enter your choice: 1

Enter the Number of Persons: 2
Enter the details of Passenger 1:
Name: Ramesh
Gender(F/M): M
Age: 30
Enter the details of Passenger 2:
Name: Sita
Gender(F/M): F
Age: 25

Select your choice:
1. Sleeper class
2. AC Class
> 2
Select the type of AC Class:
1: 1st class AC
2: 2nd class AC
3: 3rd class AC
> 3

Seat Availability:
1: Upper Berth
2: Lower Berth
3: Middle Berth
4: Side Lower Berth
5: Side Upper Berth
Enter the choice for passenger 1: 1
Enter the choice for passenger 2: 2

Do you want to have food (yes/no): yes
Select the following options:
1: Veg Thali (Rs. 200)
2: Non Veg Thali (Rs. 300)
> 1

--- RECEIPT ---
Passenger 1: Ramesh | M | 30 | Upper Berth
Passenger 2: Sita   | F | 25 | Lower Berth
Ticket Price (with GST): Rs. 5000
Food Price: Rs. 400
Total Paid: Rs. 5400

---

## How It Works
- Linked List is used to store passenger details dynamically.

- Switch-case menus for journey details, class, and food selection.

- Price Calculation includes base fare, class surcharge, and GST.

- Cancellation deducts 10% from the total amount before refund.

---

## Future Enhancements
- Add PNR generation for each booking.

- Implement seat availability tracking dynamically.

- Introduce file-based data storage for booking history.

- Enhance UI with colored output for better readability.
