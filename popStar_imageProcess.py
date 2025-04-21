from PIL import Image

def judge_color(pix):
    print(pix,end='')
    R = pix[0] > 175
    G = pix[1] > 175
    B = pix[2] > 185
    if R and G:
        return 2
    if R and B:
        return 5
    if B:
        return 3
    if R:
        return 1
    if G:
        return 4


img = Image.open('/run/media/hpp/softwaredata/Code/Projects/popStar/shot.jpg')
img = img.crop((165,605,1085,1540))
img.save('/run/media/hpp/softwaredata/Code/Projects/popStar/crop.jpg')

img = Image.open('/run/media/hpp/softwaredata/Code/Projects/popStar/crop.jpg')
pix = img.load()
width,height = img.size
out = [[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0]]
for i in range(10):
    print()
    for j in range(10):
        out[i][j] = judge_color(pix[int(width*(j*2+1)/20),int(height*(i*2+1)/20)])
print()
for i in range(10):
    for j in range(10):
        out[i][j] = str(out[i][j])
f = open("/run/media/hpp/softwaredata/Code/Projects/popStar/a.in","w")
for i in range(10):
    print(" ".join(out[i]),file = f)
f.close()
