# for bash

#
# sed 's/HoleDepth = 0.0*mm;/HoleDepth = 1.5*mm;/g' DRTileDetectorConstruction.cc > DRTileDetectorConstruction-1.cc
# rm DRTileDetectorConstruction.cc
# mv DRTileDetectorConstruction-1.cc DRTileDetectorConstruction.cc
# cmake ~/DRTile && make && make install 
#

# !!!

sed 's/0 10 0/1.5 10 1.5/g' DRTile.in > DRTile-1.in
sed 's/x_z_0_0mm/x_z_1.5_1.5mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

# !!!

#sed 's/1.5 10 1.5/4.5 10 4.5/g' DRTile.in > DRTile-1.in
#sed 's/x_z_1.5_1.5mm/x_z_4.5_4.5mm/g' DRTile-1.in > DRTile1.in
#rm -rf DRTile.in DRTile-1.in
#mv DRTile1.in DRTile.in
#./DRTile -m DRTile.in

# !!!

#sed 's/4.5 10 4.5/7.5 10 7.5/g' DRTile.in > DRTile-1.in
#sed 's/x_z_4.5_4.5mm/x_z_7.5_7.5mm/g' DRTile-1.in > DRTile1.in
#rm -rf DRTile.in DRTile-1.in
#mv DRTile1.in DRTile.in
#./DRTile -m DRTile.in

# !!!

#sed 's/7.5 10 7.5/10.5 10 10.5/g' DRTile.in > DRTile-1.in
#sed 's/x_z_7.5_7.5mm/x_z_10.5_10.5mm/g' DRTile-1.in > DRTile1.in
#rm -rf DRTile.in DRTile-1.in
#mv DRTile1.in DRTile.in
#./DRTile -m DRTile.in

# !!!

sed 's/1.5 10 1.5/13.5 10 13.5/g' DRTile.in > DRTile-1.in
sed 's/x_z_1.5_1.5mm/x_z_13.5_13.5mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
./DRTile -m DRTile.in

# !!!

sed 's/13.5 10 13.5/0 10 0/g' DRTile.in > DRTile-1.in
sed 's/x_z_13.5_13.5mm/x_z_0_0mm/g' DRTile-1.in > DRTile1.in
rm -rf DRTile.in DRTile-1.in
mv DRTile1.in DRTile.in
#./DRTile -m DRTile.in

# !!!

#sed 's/10 10 10/12 10 12/g' DRTile.in > DRTile-1.in
#sed 's/xz1010mm/xz1212mm/g' DRTile-1.in > DRTile1.in
#rm -rf DRTile.in DRTile-1.in
#mv DRTile1.in DRTile.in
#./DRTile -m DRTile.in

#sed 's/12 10 12/14 10 14/g' DRTile.in > DRTile-1.in
#sed 's/xz1212mm/xz1414mm/g' DRTile-1.in > DRTile1.in
#rm -rf DRTile.in DRTile-1.in
#mv DRTile1.in DRTile.in
#./DRTile -m DRTile.in

#sed 's/13.5 10 13.5/1.5 10 1.5/g' DRTile.in > DRTile-1.in
#sed 's/x_z_13.5_13.5mm/x_z_1.5_1.5mm/g' DRTile-1.in > DRTile1.in
#rm -rf DRTile.in DRTile-1.in
#mv DRTile1.in DRTile.in
#./DRTile -m DRTile.in

#sed 's/9 10 9/10 10 10/g' DRTile.in > DRTile-1.in
#sed 's/xz9mm/xz10mm/g' DRTile-1.in > DRTile1.in
#rm -rf DRTile.in DRTile-1.in
#mv DRTile1.in DRTile.in
#./DRTile -m DRTile.in

#sed 's/10 10 10/11 10 11/g' DRTile.in > DRTile-1.in
#sed 's/xz10mm/xz11mm/g' DRTile-1.in > DRTile1.in
#rm -rf DRTile.in DRTile-1.in
#mv DRTile1.in DRTile.in
#./DRTile -m DRTile.in

# !!!

#sed 's/2 10 2/12 10 12/g' DRTile.in > DRTile-1.in
#sed 's/xz2mm/xz12mm/g' DRTile-1.in > DRTile1.in
#rm -rf DRTile.in DRTile-1.in
#mv DRTile1.in DRTile.in
#./DRTile -m DRTile.in

# !!!

#sed 's/12 10 12/13 10 13/g' DRTile.in > DRTile-1.in
#sed 's/xz12mm/xz13mm/g' DRTile-1.in > DRTile1.in
#rm -rf DRTile.in DRTile-1.in
#mv DRTile1.in DRTile.in
#./DRTile -m DRTile.in

#sed 's/13 10 13/14 10 14/g' DRTile.in > DRTile-1.in
#sed 's/xz13mm/xz14mm/g' DRTile-1.in > DRTile1.in
#rm -rf DRTile.in DRTile-1.in
#mv DRTile1.in DRTile.in
#./DRTile -m DRTile.in

#sed 's/14 10 14/15 10 15/g' DRTile.in > DRTile-1.in
#sed 's/xz14mm/xz15mm/g' DRTile-1.in > DRTile1.in
#rm -rf DRTile.in DRTile-1.in
#mv DRTile1.in DRTile.in
#./DRTile -m DRTile.in

# !!!

#sed 's/12 10 12/1 10 1/g' DRTile.in > DRTile-1.in
#sed 's/xz12mm/xz1mm/g' DRTile-1.in > DRTile1.in
#rm -rf DRTile.in DRTile-1.in
#mv DRTile1.in DRTile.in

# !!!

