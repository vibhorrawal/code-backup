
for i = 1:10
im = imread('test.png');
imflat = double(reshape(im, size(im,1) * size(im,2), 3));
[kIDs, kC] = kmeans(imflat, i + 3, 'Display', 'iter', 'MaxIter', 150, 'Start', 'sample');

colormap = kC / 256;
imout = reshape(uint8(kIDs), size(im,1), size(im,2));
imwrite(imout - 1, colormap, strcat('test_out',int2str(i),'.png'));
end