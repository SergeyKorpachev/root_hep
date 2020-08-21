# for bash

#
# sed 's/HoleDepth = 0.0*mm;/HoleDepth = 1.5*mm;/g' DRTileDetectorConstruction.cc > DRTileDetectorConstruction-1.cc
# rm DRTileDetectorConstruction.cc
# mv DRTileDetectorConstruction-1.cc DRTileDetectorConstruction.cc
# cmake ~/DRTile && make && make install 
#

sed 's/1 10 1/2 10 2/g' DRTile.in > DRTile-1.in
sed 's/xz1mm/xz22mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/2 10 2/2 10 4/g' DRTile.in > DRTile-1.in
sed 's/xz22mm/xz24mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/2 10 4/2 10 6/g' DRTile.in > DRTile-1.in
sed 's/xz24mm/xz26mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/2 10 6/2 10 8/g' DRTile.in > DRTile-1.in
sed 's/xz26mm/xz28mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/2 10 8/2 10 10/g' DRTile.in > DRTile-1.in
sed 's/xz28mm/xz210mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/2 10 10/2 10 12/g' DRTile.in > DRTile-1.in
sed 's/xz210mm/xz212mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/2 10 12/2 10 14/g' DRTile.in > DRTile-1.in
sed 's/xz212mm/xz214mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/2 10 14/1 10 1/g' DRTile.in > DRTile-1.in
sed 's/xz214mm/xz1mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in

# !!!

sed 's/1 10 1/4 10 2/g' DRTile.in > DRTile-1.in
sed 's/xz1mm/xz42mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/4 10 2/4 10 4/g' DRTile.in > DRTile-1.in
sed 's/xz42mm/xz44mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/4 10 4/4 10 6/g' DRTile.in > DRTile-1.in
sed 's/xz44mm/xz46mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/4 10 6/4 10 8/g' DRTile.in > DRTile-1.in
sed 's/xz46mm/xz48mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/4 10 8/4 10 10/g' DRTile.in > DRTile-1.in
sed 's/xz48mm/xz410mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/4 10 10/4 10 12/g' DRTile.in > DRTile-1.in
sed 's/xz410mm/xz412mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/4 10 12/4 10 14/g' DRTile.in > DRTile-1.in
sed 's/xz412mm/xz414mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/4 10 14/1 10 1/g' DRTile.in > DRTile-1.in
sed 's/xz414mm/xz1mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in

# !!!

sed 's/1 10 1/6 10 2/g' DRTile.in > DRTile-1.in
sed 's/xz1mm/xz62mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/6 10 2/6 10 4/g' DRTile.in > DRTile-1.in
sed 's/xz62mm/xz64mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/6 10 4/6 10 6/g' DRTile.in > DRTile-1.in
sed 's/xz64mm/xz66mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/6 10 6/6 10 8/g' DRTile.in > DRTile-1.in
sed 's/xz66mm/xz68mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/6 10 8/6 10 10/g' DRTile.in > DRTile-1.in
sed 's/xz68mm/xz610mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/6 10 10/6 10 12/g' DRTile.in > DRTile-1.in
sed 's/xz610mm/xz612mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/6 10 12/6 10 14/g' DRTile.in > DRTile-1.in
sed 's/xz612mm/xz614mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/6 10 14/1 10 1/g' DRTile.in > DRTile-1.in
sed 's/xz614mm/xz1mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in

# !!!

sed 's/1 10 1/8 10 2/g' DRTile.in > DRTile-1.in
sed 's/xz1mm/xz82mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/8 10 2/8 10 4/g' DRTile.in > DRTile-1.in
sed 's/xz82mm/xz84mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/8 10 4/8 10 6/g' DRTile.in > DRTile-1.in
sed 's/xz84mm/xz86mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/8 10 6/8 10 8/g' DRTile.in > DRTile-1.in
sed 's/xz86mm/xz88mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/8 10 8/8 10 10/g' DRTile.in > DRTile-1.in
sed 's/xz88mm/xz810mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/8 10 10/8 10 12/g' DRTile.in > DRTile-1.in
sed 's/xz810mm/xz812mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/8 10 12/8 10 14/g' DRTile.in > DRTile-1.in
sed 's/xz812mm/xz814mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/8 10 14/1 10 1/g' DRTile.in > DRTile-1.in
sed 's/xz814mm/xz1mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in

# !!!

sed 's/1 10 1/10 10 2/g' DRTile.in > DRTile-1.in
sed 's/xz1mm/xz102mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/10 10 2/10 10 4/g' DRTile.in > DRTile-1.in
sed 's/xz102mm/xz104mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/10 10 4/10 10 6/g' DRTile.in > DRTile-1.in
sed 's/xz104mm/xz106mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/10 10 6/10 10 8/g' DRTile.in > DRTile-1.in
sed 's/xz106mm/xz108mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/10 10 8/10 10 10/g' DRTile.in > DRTile-1.in
sed 's/xz108mm/xz1010mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/10 10 10/10 10 12/g' DRTile.in > DRTile-1.in
sed 's/xz1010mm/xz1012mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/10 10 12/10 10 14/g' DRTile.in > DRTile-1.in
sed 's/xz1012mm/xz1014mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/10 10 14/1 10 1/g' DRTile.in > DRTile-1.in
sed 's/xz1014mm/xz1mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in

# !!!

sed 's/1 10 1/12 10 2/g' DRTile.in > DRTile-1.in
sed 's/xz1mm/xz122mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/12 10 2/12 10 4/g' DRTile.in > DRTile-1.in
sed 's/xz122mm/xz124mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/12 10 4/12 10 6/g' DRTile.in > DRTile-1.in
sed 's/xz124mm/xz126mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/12 10 6/12 10 8/g' DRTile.in > DRTile-1.in
sed 's/xz126mm/xz128mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/12 10 8/12 10 10/g' DRTile.in > DRTile-1.in
sed 's/xz128mm/xz1210mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/12 10 10/12 10 12/g' DRTile.in > DRTile-1.in
sed 's/xz1210mm/xz1212mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/12 10 12/12 10 14/g' DRTile.in > DRTile-1.in
sed 's/xz1212mm/xz1214mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/12 10 14/1 10 1/g' DRTile.in > DRTile-1.in
sed 's/xz1214mm/xz1mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in

# !!!

sed 's/1 10 1/14 10 2/g' DRTile.in > DRTile-1.in
sed 's/xz1mm/xz142mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/14 10 2/14 10 4/g' DRTile.in > DRTile-1.in
sed 's/xz142mm/xz144mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/14 10 4/14 10 6/g' DRTile.in > DRTile-1.in
sed 's/xz144mm/xz146mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/14 10 6/14 10 8/g' DRTile.in > DRTile-1.in
sed 's/xz146mm/xz148mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/14 10 8/14 10 10/g' DRTile.in > DRTile-1.in
sed 's/xz148mm/xz1410mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/14 10 10/14 10 12/g' DRTile.in > DRTile-1.in
sed 's/xz1410mm/xz1412mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/14 10 12/14 10 14/g' DRTile.in > DRTile-1.in
sed 's/xz1412mm/xz1414mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

sed 's/14 10 14/1 10 1/g' DRTile.in > DRTile-1.in
sed 's/xz1414mm/xz1mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in

# !!!
