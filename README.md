## FRANSI layout

A custom keyboard layout mixing ANSI and AZERTY, designed for
coding, built with QMK

### Build

#### 65

Copy `sixtyfive/fransi` keymap directory in QMK repo

```
qmk_firmware/keyboards/dztech/tofu/jr/keymaps/
```

Build & flash

```
qmk compile --clean -kb dztech/tofu/jr -km fransi
qmk flash -kb dztech/tofu/jr -km fransi
```

#### HHKB

Copy `hhkb/fransi` keymap directory in QMK repo

```
qmk_firmware/keyboards/hhkb/ansi/keymaps/
```

Build & flash

```
qmk compile --clean -kb hhkb/ansi/32u4 -km fransi
qmk flash -kb hhkb/ansi/32u4 -km deip
```
