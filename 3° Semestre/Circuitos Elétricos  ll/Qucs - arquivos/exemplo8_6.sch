<Qucs Schematic 0.0.18>
<Properties>
  <View=0,0,800,800,1.4641,112,189>
  <Grid=10,10,1>
  <DataSet=exemplo8_6.dat>
  <DataDisplay=exemplo8_6.dpl>
  <OpenDisplay=1>
  <Script=exemplo8_6.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <GND * 1 340 320 0 0 0 0>
  <Idc I1 1 200 260 18 -26 0 1 "24 mA" 1>
  <IProbe IL 1 460 290 40 -2 0 3>
  <IProbe IC 1 580 290 17 0 1 3>
  <IProbe IR 1 340 290 40 -2 0 3>
  <L L1 1 460 230 10 -26 0 1 "25 mH" 1 "" 0>
  <C C1 1 580 230 17 -26 0 1 "25 nF" 1 "" 0 "neutral" 0>
  <Switch S1 1 290 260 11 -26 0 1 "on" 0 "0 ns" 0 "0" 0 "1e12" 0 "26.85" 0 "1e-6" 0>
  <.TR TR1 1 120 350 0 68 0 0 "lin" 1 "0" 1 "300 us" 1 "2000" 0 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
  <R R1 1 340 230 15 -26 0 1 "625 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
</Components>
<Wires>
  <340 320 460 320 "" 0 0 0 "">
  <290 200 340 200 "" 0 0 0 "">
  <290 200 290 230 "" 0 0 0 "">
  <290 320 340 320 "" 0 0 0 "">
  <290 290 290 320 "" 0 0 0 "">
  <200 200 200 230 "" 0 0 0 "">
  <200 200 290 200 "" 0 0 0 "">
  <200 290 200 320 "" 0 0 0 "">
  <200 320 290 320 "" 0 0 0 "">
  <460 320 580 320 "" 0 0 0 "">
  <460 200 580 200 "" 0 0 0 "">
  <340 200 460 200 "" 0 0 0 "">
  <580 200 580 200 "Vp" 610 170 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
