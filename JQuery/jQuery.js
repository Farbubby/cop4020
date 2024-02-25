$(function () {
  $(".draggable").draggable();

  const pieces = $(".shuffle");
  pieces.each((i, piece) => {
    const randomX =
      Math.floor(Math.random() * 180) * (Math.random() < 0.5 ? -1 : 1);
    const randomY =
      Math.floor(Math.random() * 180) * (Math.random() < 0.5 ? -1 : 1);
    piece.style.transform = `translate(${randomX}px, ${randomY}px)`;
    piece.style.transition = "transform 1s ease";
  });

  setTimeout(() => {
    pieces.each((i, piece) => {
      piece.style.transform = "";
      piece.style.transition = "";
      piece.classList.add(`transition-${i + 1}`);
    });
  }, 1500);
});
