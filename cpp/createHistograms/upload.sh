#! /bin/sh

COPYFILE_DISABLE=1; 
export COPYFILE_DISABLE

declare -a fileList=("make.sh"
                     "upload.sh" 
                     "makeHistograms.cxx"
                     "makeHistograms.h" 
                     "headers.h" 
                     "structs.h" 
                     "createHistograms.cxx")
echo "\n"
echo "Uploading following files: "
for i in "${fileList[@]}"
do
echo "$i"
done
echo "\n"
echo "Generating upload.tar.gz file: "
for i in "${fileList[@]}"
do
tar rf upload.tar "$i"
done
gzip upload.tar
echo "Done..!"

echo "\nChecking the contents inside upload.tar: "
tar -tvf upload.tar.gz

echo "\nUploading upload.tar.gz: "
scp ./upload.tar.gz ckuruppu@novagpvm15.fnal.gov:/nova/app/users/ckuruppu/workingThesis/cpp/createHistograms/

echo "\nssh into novagpvm and clean build: "
ssh ckuruppu@novagpvm15.fnal.gov "cd /nova/app/users/ckuruppu/workingThesis/cpp/createHistograms/ &&
                                  tar xopf upload.tar.gz &&
                                  rm upload.tar.gz &&
                                  echo 'upload.tar.gz was deleted successfully..!' 
                                  "

rm upload.tar.gz
