## ✈️ Airline Reservation and Management System

A comprehensive airline reservation platform developed in **Java** using **Object-Oriented Programming (OOP)** principles, **multithreading**, **GUI development**, and **unit testing** techniques. The project simulates a real-world airline management environment where users can search flights, reserve seats, purchase tickets, and manage reservations while administrators maintain flight information.

---

### 📖 Project Overview

The Airline Reservation and Management System was designed to model the core operations of a modern airline company. The application provides separate functionalities for passengers and administrators while maintaining a modular and extensible software architecture.

The project emphasizes:

- Object-Oriented Design
- Concurrent Programming
- GUI Development
- Unit Testing
- Software Architecture
- File-Based Data Persistence

---

### 🚀 Features

#### Flight Management

- Create new flights
- Edit existing flight information
- Delete flights
- Manage flight schedules
- Manage departure and arrival routes
- Track aircraft capacity

#### Reservation Management

- Search available flights
- Reserve seats
- Cancel reservations
- View reservation details
- Generate unique reservation codes

#### Ticketing System

- Ticket generation
- Automatic price calculation
- Economy and Business class support
- Baggage allowance management
- Reservation-to-ticket conversion

#### Seat Management

- Dynamic seat allocation
- Seat occupancy tracking
- Available seat calculation
- Prevention of double booking

#### Administrative Tools

- Flight creation and modification
- Reservation monitoring
- Occupancy analysis
- Airline operations management

---

### 🏗️ System Architecture

The system follows a modular object-oriented architecture.

#### Core Domain Classes

##### Plane

Represents an aircraft.

**Attributes:**

- planeID
- planeModel
- capacity
- seatMatrix

**Responsibilities:**

- Store aircraft information
- Maintain seat configuration
- Provide seat availability data

---

##### Flight

Represents a scheduled flight.

**Attributes:**

- flightNumber
- departurePlace
- arrivalPlace
- date
- time
- duration

**Responsibilities:**

- Manage flight schedules
- Store route information
- Connect aircraft and passengers

---

##### Seat

Represents an individual seat.

**Attributes:**

- seatNumber
- seatClass
- price
- reservationStatus

**Responsibilities:**

- Store seat information
- Manage reservation state
- Support different ticket classes

---

##### Route

Represents travel information.

**Responsibilities:**

- Departure location management
- Arrival location management
- Route organization

---

##### Passenger

Represents airline customers.

**Attributes:**

- passengerID
- name
- surname
- contactInformation

**Responsibilities:**

- Store passenger data
- Link passengers to reservations

---

##### Reservation

Represents seat bookings.

**Attributes:**

- reservationCode
- flight
- passenger
- seat
- reservationDate

**Responsibilities:**

- Connect passengers and flights
- Manage reservation lifecycle

---

##### Ticket

Represents purchased flight tickets.

**Attributes:**

- ticketID
- reservation
- price
- baggageAllowance

**Responsibilities:**

- Store ticket information
- Manage baggage limits
- Calculate travel costs

---

### ⚙️ Service Layer

#### FlightManager

Responsible for:

- Creating flights
- Updating flights
- Deleting flights
- Searching flights

---

#### SeatManager

Responsible for:

- Seat allocation
- Occupancy calculations
- Available seat tracking
- Seat validation

---

#### ReservationManager

Responsible for:

- Reservation creation
- Reservation cancellation
- Concurrent reservation operations

---

#### CalculatePrice

Responsible for:

- Economy ticket pricing
- Business ticket pricing
- Fare calculations
- Business logic implementation

---

### 🧵 Multithreading Implementation

One of the most important aspects of the project is the use of concurrent programming.

---

#### Scenario 1: Simultaneous Seat Reservation

A simulation was developed to demonstrate race conditions and synchronization mechanisms.

**Simulation Details:**

- Aircraft capacity: 180 seats
- Passenger count: 90
- Each passenger runs in a separate thread
- Seats are selected randomly

**Features:**

- Real-time seat occupancy visualization
- Synchronization toggle
- Multiple simulation runs
- Occupied and empty seat statistics

**Synchronized Mode:**

- Correct seat allocation
- Exactly 90 occupied seats
- No duplicate reservations

**Unsynchronized Mode:**

- Demonstrates race conditions
- Potential reservation conflicts
- Incorrect seat assignments

This scenario highlights the importance of synchronization in concurrent systems.

---

#### Scenario 2: Asynchronous Report Generation

A separate reporting thread is used to prevent the GUI from freezing during expensive computations.

**Features:**

- Independent report generation thread
- Non-blocking GUI
- Background processing
- Real-time status updates

**Workflow:**

1. User requests report generation.
2. GUI remains responsive.
3. ReportGenerator thread performs calculations.
4. Results are returned asynchronously.

This implementation demonstrates modern asynchronous application design.

---

### 🧪 Unit Testing

The project includes automated testing using **JUnit 5**.

#### Price Calculation Tests

Tests verify:

- Economy ticket pricing
- Business ticket pricing
- Correct fare calculations

#### Flight Search Tests

Tests verify:

- Correct route filtering
- Flight retrieval accuracy
- Removal of expired flights

#### Seat Manager Tests

Tests verify:

- Seat count updates
- Successful reservations
- Exception handling
- Invalid seat detection

---

### 🖥️ Graphical User Interface

The application includes a complete desktop GUI developed using Java technologies.

#### Login Screen

- User authentication
- Staff authentication

#### Flight Search & Booking Screen

- Search flights
- Select seats
- Create reservations
- Ticket purchasing

#### Reservation Management Screen

- View reservations
- Search reservations
- Cancel reservations

#### Admin Dashboard

- Add flights
- Edit schedules
- Manage airline operations
- Monitor occupancy rates

---

### 💾 Data Persistence

The project uses file-based storage instead of databases.

**Features:**

- Permanent data storage
- Lightweight deployment
- Easy file management
- No external database dependency

**Stored Information:**

- Flights
- Passengers
- Reservations
- Tickets
- Seat information

---

### 🛠️ Technologies Used

- Java
- JavaFX / Swing
- JUnit 5
- Multithreading
- Object-Oriented Programming
- File I/O
- UML Design

---

### 🎯 Learning Outcomes

This project provided practical experience in:

- Object-Oriented Software Design
- GUI Application Development
- Thread Synchronization
- Race Condition Handling
- Asynchronous Programming
- Unit Testing
- File-Based Storage
- UML-Based System Modeling
- Real-World Software Architecture

---

### 📌 Summary

The Airline Reservation and Management System is a complete Java-based desktop application that combines OOP, GUI design, multithreading, testing, and persistent storage. It models a realistic airline workflow while demonstrating important software engineering concepts such as modular design, concurrency control, and maintainable architecture.
