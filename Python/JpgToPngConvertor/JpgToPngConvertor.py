'''
Copyright [2020] [Arun Kumar G]
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
'''

'''
Script uses Pillow module to read the image and convert it to png.
sys module for accepting inputs from terminal and os module 
for operations on pathnames.

Install Pillow module through "pip install pillow"
'''

import sys,os
from PIL import Image

source_folder = sys.argv[1]  # Accepts source folder given in terminal
destination_folder = sys.argv[2] # Accepts destination folder given in terminal

if not os.path.exists(destination_folder):  #Check if destination folder exists,if not creates one
    os.makedirs(destination_folder)

for filename in os.listdir(source_folder): # For each file present in Source folder
    file = os.path.splitext(filename)[0]  # Splits file name into as tuple as ('filename','.extension')
    img = Image.open(f'{source_folder}/{filename}')
    img.save(f'{destination_folder}/{file}.png','png') #Converts to png format
    print("Image converted!")

'''
Sample input to run in terminal:
->Python3 JpgToPngConvertor.py Source_Images Destination_Images

Output:
Images in Source_Images folder will be converted into Png Images and gets stored in
Destination_Images folder
'''




