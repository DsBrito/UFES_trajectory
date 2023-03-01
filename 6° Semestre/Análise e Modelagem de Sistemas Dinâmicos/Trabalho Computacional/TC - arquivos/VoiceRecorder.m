recObj = audiorecorder(192000, 16, 1)
disp('Start speaking.')
recordblocking(recObj, 8.9634);
disp('End of Recording.');
play(recObj);
y = getaudiodata(recObj);
Fs = recObj.SampleRate

% By default, an audiorecorder object uses a sample rate of 8000 hertz, a 
% depth of 8 bits (8 bits per sample), and a single audio channel. These 
% settings minimize the required amount of data storage. For higher 
% quality recordings, increase the sample rate or bit depth.
% For example, typical compact disks use a sample rate of 44,100 hertz and
% a 16-bit depth. Create an audiorecorder object to record in stereo (two 
% channels) with those settings:
% 
% myRecObj = audiorecorder(44100, 16, 2);
% For more information on the available properties and values, see the
% audio recorder reference page.

audiowrite('audioAvaliacaoPC.wav',y,Fs);