#!/bin/bash

# Renk kodları
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Test sayacı
count=0
max_moves=0
total_moves=0

# Ana dizine erişim
MAIN_DIR="../"

# 4 elemanlı tüm permütasyonları test et
for a in {1..4}; do
    for b in {1..4}; do
        for c in {1..4}; do
            for d in {1..4}; do
                # Tekrarlanan sayı olmamasını kontrol et
                if [ $a != $b ] && [ $a != $c ] && [ $a != $d ] && \
                   [ $b != $c ] && [ $b != $d ] && [ $c != $d ]; then
                    
                    # Test edilecek sayıları hazırla
                    ARG="$a $b $c $d"
                    
                    # Zaten sıralı mı kontrol et
                    is_sorted=1
                    prev=0
                    for num in $ARG; do
                        if [ $num -le $prev ] && [ $prev -ne 0 ]; then
                            is_sorted=0
                            break
                        fi
                        prev=$num
                    done
                    
                    # Sıralı ise atla
                    if [ $is_sorted -eq 1 ]; then
                        continue
                    fi
                    
                    count=$((count + 1))
                    
                    # Virgülle ayrılmış dizileri hazırla
                    ARG_COMMA=$(echo $ARG | sed 's/ /, /g')
                    SORTED="1, 2, 3, 4"
                    
                    # push_swap'i çalıştır
                    moves_output=$($MAIN_DIR/push_swap $ARG)
                    moves_count=$(echo "$moves_output" | wc -l)
                    
                    # checker ile kontrol et
                    result=$(echo "$moves_output" | $MAIN_DIR/checker_linux $ARG)
                    
                    # Sonucu formatla
                    if [ "$result" == "OK" ]; then
                        result_colored="${GREEN}OK${NC}"
                    else
                        result_colored="${RED}KO${NC}"
                    fi
                    
                    # Üç basamaklı test numarası formatı (001, 002, ...)
                    formatted_count=$(printf "%03d" $count)
                    
                    # İki basamaklı hamle sayısı formatı (05, 08, 10, ...)
                    formatted_moves=$(printf "%02d" $moves_count)
                    
                    # İstenen formatta yazdır
                    echo -e "$formatted_count.) [$ARG_COMMA] → [$SORTED]: $formatted_moves [ $result_colored ]"
                    
                    # İstatistikleri güncelle
                    total_moves=$((total_moves + moves_count))
                    if [ $moves_count -gt $max_moves ]; then
                        max_moves=$moves_count
                    fi
                fi
            done
        done
    done
done

# Özet istatistikleri yazdır
echo
echo "Number of permutations tested: $count"
echo "Maximum number of moves: $max_moves"
echo "Average number of moves: $(echo "scale=2; $total_moves / $count" | bc)"
