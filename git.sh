#!/bin/bash

set -e

echo "========== Git 自动提交 =========="

echo "[1/3] 添加文件..."
git add .

echo "[2/3] 提交..."
git commit -m "继续学习"

echo "[3/3] 推送..."
git push

echo "========== 完成 =========="