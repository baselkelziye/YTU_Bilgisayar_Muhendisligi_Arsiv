@echo off
echo ============================
echo TUM MODELLER EGITILIYOR...
echo ============================

:: GOREV 1
echo ----------------------------
echo GOREV 1 - CNN - 1
python train.py --task 1 --model cnn --portion 100 --dropout 0.0 --wd 0.0 --lr 1e-3
echo GOREV 1 - CNN - 2
python train.py --task 1 --model cnn --portion 100 --dropout 0.3 --wd 0.0 --lr 1e-3
echo GOREV 1 - CNN - 3
python train.py --task 1 --model cnn --portion 100 --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 1 - CNN - 4
python train.py --task 1 --model cnn --portion 50  --dropout 0.5 --wd 1e-3 --lr 1e-3
echo GOREV 1 - CNN - 5
python train.py --task 1 --model cnn --portion 25  --dropout 0.5 --wd 1e-4 --lr 1e-4

echo GOREV 1 - MLP - 1
python train.py --task 1 --model mlp --portion 100 --dropout 0.0 --wd 0.0 --lr 1e-3
echo GOREV 1 - MLP - 2
python train.py --task 1 --model mlp --portion 100 --dropout 0.3 --wd 0.0 --lr 1e-3
echo GOREV 1 - MLP - 3
python train.py --task 1 --model mlp --portion 100 --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 1 - MLP - 4
python train.py --task 1 --model mlp --portion 50  --dropout 0.5 --wd 1e-3 --lr 1e-3
echo GOREV 1 - MLP - 5
python train.py --task 1 --model mlp --portion 25  --dropout 0.5 --wd 1e-4 --lr 1e-4

:: GOREV 2
echo ----------------------------
echo GOREV 2 - CNN - 1
python train.py --task 2 --model cnn --portion 100 --dropout 0.0 --wd 0.0 --lr 1e-3
echo GOREV 2 - CNN - 2
python train.py --task 2 --model cnn --portion 100 --dropout 0.3 --wd 0.0 --lr 1e-3
echo GOREV 2 - CNN - 3
python train.py --task 2 --model cnn --portion 50  --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 2 - CNN - 4
python train.py --task 2 --model cnn --portion 50  --dropout 0.5 --wd 1e-3 --lr 1e-3
echo GOREV 2 - CNN - 5
python train.py --task 2 --model cnn --portion 25  --dropout 0.5 --wd 1e-3 --lr 1e-4

echo GOREV 2 - MLP - 1
python train.py --task 2 --model mlp --portion 100 --dropout 0.0 --wd 0.0 --lr 1e-3
echo GOREV 2 - MLP - 2
python train.py --task 2 --model mlp --portion 100 --dropout 0.3 --wd 0.0 --lr 1e-3
echo GOREV 2 - MLP - 3
python train.py --task 2 --model mlp --portion 50  --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 2 - MLP - 4
python train.py --task 2 --model mlp --portion 50  --dropout 0.5 --wd 1e-3 --lr 1e-3
echo GOREV 2 - MLP - 5
python train.py --task 2 --model mlp --portion 25  --dropout 0.5 --wd 1e-3 --lr 1e-4


:: GOREV 3
echo ----------------------------
echo GOREV 3 - CNN - 1
python train.py --task 3 --model cnn --portion 100 --dropout 0.0 --wd 0.0 --lr 1e-3
echo GOREV 3 - CNN - 2
python train.py --task 3 --model cnn --portion 100 --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 3 - CNN - 3
python train.py --task 3 --model cnn --portion 50  --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 3 - CNN - 4
python train.py --task 3 --model cnn --portion 50  --dropout 0.5 --wd 1e-3 --lr 1e-3
echo GOREV 3 - CNN - 5
python train.py --task 3 --model cnn --portion 25  --dropout 0.5 --wd 1e-3 --lr 1e-4


echo GOREV 3 - MLP - 1
python train.py --task 3 --model mlp --portion 100 --dropout 0.0 --wd 0.0 --lr 1e-3
echo GOREV 3 - MLP - 2
python train.py --task 3 --model mlp --portion 100 --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 3 - MLP - 3
python train.py --task 3 --model mlp --portion 50  --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 3 - MLP - 4
python train.py --task 3 --model mlp --portion 50  --dropout 0.5 --wd 1e-3 --lr 1e-3
echo GOREV 3 - MLP - 5
python train.py --task 3 --model mlp --portion 25  --dropout 0.5 --wd 1e-3 --lr 1e-4

:: GOREV 4
echo ----------------------------
echo GOREV 4 - CNN - 1
python train.py --task 4 --model cnn --portion 100 --dropout 0.0 --wd 0.0 --lr 1e-3
echo GOREV 4 - CNN - 2
python train.py --task 4 --model cnn --portion 100 --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 4 - CNN - 3
python train.py --task 4 --model cnn --portion 50  --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 4 - CNN - 4
python train.py --task 4 --model cnn --portion 50  --dropout 0.5 --wd 1e-3 --lr 1e-3
echo GOREV 4 - CNN - 5
python train.py --task 4 --model cnn --portion 25  --dropout 0.5 --wd 1e-3 --lr 1e-4

echo GOREV 4 - MLP - 1
python train.py --task 4 --model mlp --portion 100 --dropout 0.0 --wd 0.0 --lr 1e-3
echo GOREV 4 - MLP - 2
python train.py --task 4 --model mlp --portion 100 --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 4 - MLP - 3
python train.py --task 4 --model mlp --portion 50  --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 4 - MLP - 4
python train.py --task 4 --model mlp --portion 50  --dropout 0.5 --wd 1e-3 --lr 1e-3
echo GOREV 4 - MLP - 5
python train.py --task 4 --model mlp --portion 25  --dropout 0.5 --wd 1e-3 --lr 1e-4

:: GOREV 5
echo ----------------------------
echo GOREV 5 - CNN - 1
python train.py --task 5 --model cnn --portion 100 --dropout 0.0 --wd 0.0 --lr 1e-3
echo GOREV 5 - CNN - 2
python train.py --task 5 --model cnn --portion 100 --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 5 - CNN - 3
python train.py --task 5 --model cnn --portion 50  --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 5 - CNN - 4
python train.py --task 5 --model cnn --portion 50  --dropout 0.5 --wd 1e-3 --lr 1e-3
echo GOREV 5 - CNN - 5
python train.py --task 5 --model cnn --portion 25  --dropout 0.5 --wd 1e-3 --lr 1e-4

echo GOREV 5 - MLP - 1
python train.py --task 5 --model mlp --portion 100 --dropout 0.0 --wd 0.0 --lr 1e-3
echo GOREV 5 - MLP - 2
python train.py --task 5 --model mlp --portion 100 --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 5 - MLP - 3
python train.py --task 5 --model mlp --portion 50  --dropout 0.3 --wd 1e-4 --lr 1e-3
echo GOREV 5 - MLP - 4
python train.py --task 5 --model mlp --portion 50  --dropout 0.5 --wd 1e-3 --lr 1e-3
echo GOREV 5 - MLP - 5
python train.py --task 5 --model mlp --portion 25  --dropout 0.5 --wd 1e-3 --lr 1e-4

echo ============================
echo EGITIMLER TAMAMLANDI
echo ============================
pause
