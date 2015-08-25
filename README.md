# ATS 
Analysis of sound

This project is a C++ little software for MacOsX I've written for a university project so it's does not purpoting anything.
It's using OpenFrameworks, a very cool open-source framework (http://www.openframeworks.cc/) for creative projects.
It also makes an extensive use of the Cooley-Tuckey FFT algorithm written by Sergey Chernenko that you can find here : http://www.librow.com/articles/article-10


**What does really do ATS ?**

It analyses the sound listened by the micro of a computer, gets the spectrum frequency out of it and creates little
animations based on those frequencies.
It basically proposes four options :
- a broken line effect : a white line over a black screen that's moving as the same time as amplitudes and frequencies of the sound.
- a line effect : lines appeared when the amplitudes of a frequency is exceeding a threshold (meaning that frequency is predominant in the song)
- two equalizers : ugly and basic equalizers
- a matrix effect : reproducing the green visual effects of *The Matrix* (just for fun).

The app has a Syphon client so it can be used along with other softwares like MadMapper.

