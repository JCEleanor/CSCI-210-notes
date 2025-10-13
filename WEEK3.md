Without -e:

1 $ echo "Line 1\nLine 2\t(indented)"
2 Line 1\nLine 2\t(indented)

With -e:

1 $ echo -e "Line 1\nLine 2\t(indented)"
2 Line 1
3 Line 2 (indented)
