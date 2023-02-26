<Qucs Schematic 0.0.18>
<Properties>
  <View=0,123,997,663,0.683014,0,0>
  <Grid=10,10,1>
  <DataSet=RC.dat>
  <DataDisplay=RC.dpl>
  <OpenDisplay=1>
  <Script=RC.m>
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
  <Eqn Eqn1 1 100 200 -23 15 0 0 "d2=phase(Vout.v)" 1 "d1=dB(Vout.v)" 1 "yes" 0>
  <GND * 1 510 380 0 0 0 0>
  <L L1 1 350 260 -26 10 0 0 "100 mH" 1 "" 0>
  <C C1 1 450 260 -18 -53 0 0 "10 mF" 1 "" 0 "neutral" 0>
  <R R2 1 520 330 15 -26 0 1 "11" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <Vac V1 1 280 330 -69 -11 0 1 "1" 1 "1 Hz" 0 "0" 0 "0" 0>
  <.AC AC1 1 80 450 0 43 0 0 "log" 1 "0.1 Hz" 1 "10 kHz" 1 "50" 1 "no" 0>
</Components>
<Wires>
  <480 260 520 260 "" 0 0 0 "">
  <520 260 520 300 "" 0 0 0 "">
  <520 360 520 380 "" 0 0 0 "">
  <510 380 520 380 "" 0 0 0 "">
  <280 380 510 380 "" 0 0 0 "">
  <280 360 280 380 "" 0 0 0 "">
  <380 260 420 260 "" 0 0 0 "">
  <280 260 320 260 "" 0 0 0 "">
  <280 260 280 300 "" 0 0 0 "">
  <520 260 520 260 "Vout" 550 230 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
