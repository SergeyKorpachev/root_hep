# for bash

root -l -q DRTileMPV.c
mv pic.jpg 2.jpg

# !!!

sed 's/cc = 2/cc = 4/g' DRTileMPV.c > DRTileMPV-1.c
mv DRTileMPV-1.c DRTileMPV.c
rm -rf DRTileMPV-1.c
root -l -q DRTileMPV.c
mv pic.jpg 4.jpg

# !!!

sed 's/cc = 4/cc = 6/g' DRTileMPV.c > DRTileMPV-1.c
mv DRTileMPV-1.c DRTileMPV.c
rm -rf DRTileMPV-1.c
root -l -q DRTileMPV.c
mv pic.jpg 6.jpg

# !!!

sed 's/cc = 6/cc = 8/g' DRTileMPV.c > DRTileMPV-1.c
mv DRTileMPV-1.c DRTileMPV.c
rm -rf DRTileMPV-1.c
root -l -q DRTileMPV.c
mv pic.jpg 8.jpg

# !!!

sed 's/cc = 8/cc = 10/g' DRTileMPV.c > DRTileMPV-1.c
mv DRTileMPV-1.c DRTileMPV.c
rm -rf DRTileMPV-1.c
root -l -q DRTileMPV.c
mv pic.jpg 10.jpg

# !!!

sed 's/cc = 10/cc = 12/g' DRTileMPV.c > DRTileMPV-1.c
mv DRTileMPV-1.c DRTileMPV.c
rm -rf DRTileMPV-1.c
root -l -q DRTileMPV.c
mv pic.jpg 12.jpg

# !!!

sed 's/cc = 12/cc = 14/g' DRTileMPV.c > DRTileMPV-1.c
mv DRTileMPV-1.c DRTileMPV.c
rm -rf DRTileMPV-1.c
root -l -q DRTileMPV.c
mv pic.jpg 14.jpg

# !!!

sed 's/cc = 14/cc = 2/g' DRTileMPV.c > DRTileMPV-1.c
mv DRTileMPV-1.c DRTileMPV.c
rm -rf DRTileMPV-1.c

# !!!
