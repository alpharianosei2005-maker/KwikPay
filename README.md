# KwikPay – Mobile Money USSD Simulator (*777#)

A command-line mobile money USSD simulator written in C that models core mobile wallet operations, input validation, and transaction logging.

## Download & Run (Windows Executable)

You don't need a C compiler to test the app! Grab the ready-to-run Windows executable (**KwikPay v1.0.0**) from the **[Releases](https://github.com/alpharianosei2005-maker/KwikPay/releases/tag/v1.0.0)** section.

1. Download `kwikpay.exe` from the [v1.0.0 Release page](https://github.com/alpharianosei2005-maker/KwikPay/releases/tag/v1.0.0).
2. Double-click `kwikpay.exe` to run it *(if Windows SmartScreen appears, click **More info → Run anyway**)*.
3. Enter the default PIN **`1234`** to log in.

---

## Features

* **PIN Authentication:** 4-digit PIN login with automatic account lockout after 3 failed attempts.
* **Check Balance:** Displays current wallet balance in GHS.
* **Send Money:** Peer-to-peer transfers with a 1% transaction fee calculation and insufficient-balance validation.
* **Buy Airtime:** Instant airtime top-ups with balance deduction.
* **Mini Statement:** Tracks and displays a rolling history of the last 5 transactions using arrays.
* **Change PIN:** Allows users to update their 4-digit PIN with confirmation and length validation.

---

## Build from Source

If you want to compile the C source code yourself:

```bash
gcc Kwikpay.c -o kwikpay
./kwikpay
