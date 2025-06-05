# Rock Paper Scissors – Provably Fair (C++)

This is a basic Rock Paper Scissors game made in C++20. The twist is that it uses **client seed** and **server seed** to make sure the game is provably fair — meaning the computer can’t cheat.

# How it works

- You enter a **client seed** (any string you want).
- The game secretly generates a **server seed** and shows you its SHA256 hash (so it can’t change it later).
- Each round uses both seeds + a nonce (the round number) to calculate the result using **HMAC-SHA256**.
- After the game ends, you get to see the real server seed and verify everything was fair.

# Why seeds?

The idea is: if the server gives you a hash of its secret **before** the game, and you give your client seed, then neither side can cheat after that.  
You can check every round’s outcome yourself if you want.

# Requirements

- C++20
- [vcpkg](https://github.com/microsoft/vcpkg)
- OpenSSL installed with:
vcpkg install openssl:x64-windows

# How to play

Build the project.
Run the game.
Enter your client seed.
Play rounds by picking 0 (rock), 1 (paper), or 2 (scissors).
Game tells you the result.
At the end, it shows the real server seed so you can verify everything.

# How to verify a round

Let’s say:
	Your client seed was "abc"
	Server seed was "xyz"
	Round number (nonce) was 0

You calculate:
	message = "abc-0"
	hash = HMAC_SHA256("xyz", message)
	result = first 8 hex digits of hash - convert to int - % 3

That gives the same result the game showed. So it was fair.