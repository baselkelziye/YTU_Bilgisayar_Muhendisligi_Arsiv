from PIL import Image, ImageDraw
import random

def generate_complex_image(width=400, height=600, num_of_colors=10):
    colors = [(random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)) for _ in range(num_of_colors)]

    img = Image.new('RGB', (width, height))
    draw = ImageDraw.Draw(img)

    segment_width = width // num_of_colors
    prev_bottom_color = random.choice(colors)
    for i in range(num_of_colors):
        top_color = prev_bottom_color
        bottom_color = random.choice(colors)
        
        for j in range(segment_width):
            draw.line([(i*segment_width + j, 0), (i*segment_width + j, height//2)], fill=top_color)
            draw.line([(i*segment_width + j, height//2), (i*segment_width + j, height)], fill=bottom_color)
        
        prev_bottom_color = bottom_color
    img.save('Color-Table.bmp')
    img.show()
    return img

def generate_gray_gradient_image(width=400, height=600, num_of_shades=20):
    shades = sorted([random.randint(0, 255) for _ in range(num_of_shades)])

    img = Image.new('L', (width, height))
    draw = ImageDraw.Draw(img)

    # Her rengin kullanılacağı piksel sayısı
    shade_width = width // num_of_shades
    shade_height = height // num_of_shades

    for i, shade in enumerate(shades):
        # Dikdörtgenlerin üst ve alt koordinatlarını hesapla
        upper_left_x = i * shade_width
        upper_left_y = 0
        lower_right_x = (i+1) * shade_width
        lower_right_y = (i+1) * shade_height

        # Dikdörtgeni çiz
        draw.rectangle([upper_left_x, upper_left_y, lower_right_x, lower_right_y], fill=shade)

        # Diğer yarı için dikdörtgeni çiz
        upper_left_x = 0
        upper_left_y = i * shade_height
        lower_right_x = (i+1) * shade_width
        lower_right_y = (i+1) * shade_height

        draw.rectangle([upper_left_x, upper_left_y, lower_right_x, lower_right_y], fill=shade)


    img.save('Gray-Scale.bmp')
    img.show()
    return img

def generate_alternate_pattern(width=400, height=600, white_chance=0.05):
    img = Image.new('L', (width, height))
    current_color = 255  # Beyaz
    for y in range(height):
        for x in range(width):
            if random.random() < white_chance:
                # Belirli bir olasılıkla rengi tersine çevir
                pixel_color = 0 if current_color == 255 else 255
            else:
                pixel_color = current_color

            img.putpixel((x, y), pixel_color)
        
        # Her satır için ana rengi değiştir
        current_color = 0 if current_color == 255 else 255
    img.save('Black&White.bmp')
    img.show()
    return img

generate_complex_image()
generate_gray_gradient_image()
generate_alternate_pattern()
