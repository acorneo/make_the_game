# make the game plan for development
## Why does this file exist? A small moral digression
This is not the first attempt to create **make the game**. The first one, where I spent around 7 hours (just typing code), failed dramatically. Mistakes are unavoidable and I'm grateful that the realization of my errors came not after a month of active development. I was trying to do too much stuff in too little time interval. That lead me to uncontrollably relying on AI, asking for things I have absolutely no clue about. Another thing I was wrong about my ability to create everything from scratch. For example the initial idea was to create UI from nothing using just SDL and OpenGL. I don’t deny that I could do such things but it distracts me from focusing on the engine mechanics as much as on things that were created before me. I'm doing it all on my own so I should use what people have already created. So here are some *precepts* for **make the game 2.0**:  
#### 1. Plan first
Before actually writing code I should make architecture of my program. I should plan and see how every single feature works. Most of the stuff should be defined before coding starts, so my failure won't happen again.
#### 2. Understand stuff
I will try to use as little AI as possible (I hope zero); only documentation and search engines like Google. Even if I copy code from somewhere I should every single line of it. Otherwise it will lead for garbage. Code never works on the first try, so debug is unavoidable. 
#### 3. Mistakes are fine
It was mentioned before, and I should repeat it because it's so true. There is no way to create something and make no mistakes. So I should be tolerant to myself and give myself some time to think about stuff, maybe change something. This project was initially created for the Summer of Making at Hack Club, and I should try to ship my project ASAP. But I give myself full control over when and how I will work on **make the game**. I mean I don't owe anyone anything about this project except myself, it’s completely free and Open-Source.
#### 4. Follow these steps
Yep, those cannot be changed. Especially deleted. Maybe something will be added.  

All of this text was more for me than for people who are checking out this project, but it could give you some understanding about background of creating **make the game**.

## Actual plan
(english second language; grammar is terrible)  
**What am I creating:** a tool where people who are not familliar with programming are creating their games. It should be intuitive and simple, like Scratch! So I need not just a C++ library or something like that, I am looking into GUI application where people can: 1. See initial sprites position, size and all of that, I mean, just see sprites. 2. Can use code blocks, let's call them like that, to create actual scripts. Project has huge space to future features, but let's focus on:  
-> Window with initial Sprites, background and stuff.  
-> Window where people are drag-n'droppin' code blocks, programming.  
That's it. First version is ready when those two are working.  

---
**Required features:**  
-> App should be cross-platform. Mobiles - no, but Linux/Windows support should be a major requirement. I have no Mac PC so probably I will not be able to test mac version probably.  
-> Code blocks as mentioned before, sprites also mentioned before, backgrounds.  
-> Being able to export app as executable. For now we are again talking only about Windows and Linux.

---
**Tools:**
I will use raylib to create the engine UI. Still I don't want to use Qt or something like that, and imgui is like... OK I just want to try myself in this :). Raylib is also going to be used to create executables because I like it! So basically I am going to write a *compiler* that from the blocks it creates actual executables. This is also going to be a great optimization!

---
**Plan!** For the third time.  
Phase 1: Core functionality. Implement Basic editor UI, develop sprite system.  
Phase 2: dragendropen. I will call it like this, sounds cool!!! Implement blocks and a compiler for this.  
Phase 3: Implement cross-platform building proccess.  
Phase 4: Make engine work OK on Windows too.  
Phase 5: Testing all the stuff, writing documentation.  

---
Ok so spent an hour on that and probably this is the time to build this.