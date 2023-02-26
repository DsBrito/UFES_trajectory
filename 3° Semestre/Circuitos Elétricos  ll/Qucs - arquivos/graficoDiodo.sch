<Qucs Schematic 0.0.18>
<Properties>
  <View=0,190,800,694,1.61051,0,0>
  <Grid=10,10,1>
  <DataSet=graficoDiodo.dat>
  <DataDisplay=graficoDiodo.dpl>
  <OpenDisplay=1>
  <Script=graficoDiodo.m>
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
  <.TR TR1 1 80 430 0 68 0 0 "lin" 1 "0" 1 "3 ms" 1 "5001" 0 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
  <Eqn Eqn1 1 450 450 -23 15 0 0 "ID=Vout.Vt/R1.R" 1 "yes" 0>
  <Eqn Eqn2 1 450 540 -23 15 0 0 "VD=Vin.Vt-Vout.Vt" 1 "yes" 0>
  <GND * 1 460 370 0 0 1 2>
  <R R1 1 490 260 -26 -45 1 0 "1000 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <Diode D1 1 410 260 -26 15 1 2 "1e-15 A" 0 "1" 0 "10 fF" 0 "0.5" 0 "0.7 V" 0 "0.5" 0 "0.0 fF" 0 "0.0" 0 "2.0" 0 "0.0 Ohm" 0 "0.0 ps" 0 "0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0" 0 "1 mA" 0 "26.85" 0 "3.0" 0 "1.11" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "1.0" 0 "normal" 0>
  <Vac V1 1 360 320 -58 -26 1 1 "10 V" 1 "1000 Hz" 0 "0" 0 "0" 0>
  <Eqn Eqn3 1 450 630 -23 15 0 0 "y=PlotVs(ID,VD)" 1 "yes" 0>
</Components>
<Wires>
  <360 350 360 370 "" 0 0 0 "">
  <360 260 360 290 "" 0 0 0 "">
  <360 260 380 260 "" 0 0 0 "">
  <440 260 460 260 "" 0 0 0 "">
  <520 260 520 370 "" 0 0 0 "">
  <460 370 520 370 "" 0 0 0 "">
  <360 370 460 370 "" 0 0 0 "">
  <440 260 440 260 "Vout" 410 230 0 "">
  <360 260 360 260 "Vin" 330 230 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
