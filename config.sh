if uname | grep -q "Darwin"
then
    sed -i '' "s/elf/macho64/" Makefile
    echo "Mac configuration"
elif uname | grep -q "Linux"
then
    sed -i '' "s/macho64/elf/" Makefile
    echo "Linux configuration"
fi