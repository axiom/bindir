# Change the font size in a running urxvt.
# Only argument should be the font size in pixels.
# e.g. $0 13 (without any argument size is set to 13)

BASE="Envy Code R"
SIZE=13

# Take size from first argument if any.
[ $1 ] && SIZE=$1

FONT="xft:$BASE:antialias=false"
BFONT="${FONT}:bold"
BIFONT="${BFONT}:italic"
IFONT="${FONT}:italic"

printf '\033]710;%s%d\007' "${FONT}:pixelsize=" $SIZE
printf '\033]711;%s%d\007' "${BFONT}:pixelsize=" $SIZE
printf '\033]712;%s%d\007' "${BIFONT}:pixelsize=" $SIZE
printf '\033]713;%s%d\007' "${IFONT}:pixelsize=" $SIZE
