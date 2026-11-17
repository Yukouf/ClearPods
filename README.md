<p align="center"><img src="docs/logo.png" width="112" alt="ClearPods"></p>

<h1 align="center">ClearPods</h1>

<p align="center"><b>Use your AirPods mic on Windows without the muffled sound.</b><br>
Stereo audio and the AirPods microphone at the same time, for Discord, games and calls.</p>

<p align="center">
  <a href="https://github.com/Yukouf/ClearPods/releases/latest"><b>Download</b></a> ·
  <a href="#install">Install</a> ·
  <a href="#how-it-works">How it works</a> ·
  <a href="#faq">FAQ</a>
</p>

[![Latest release](https://img.shields.io/github/v/release/Yukouf/ClearPods)](https://github.com/Yukouf/ClearPods/releases/latest)
![Windows 11](https://img.shields.io/badge/Windows-11-0f9488)
![License GPL-3.0](https://img.shields.io/badge/license-GPL--3.0-0f9488)

## The problem

You connect your AirPods to a Windows PC, start a game, join Discord and talk. The moment the mic turns on, **everything you hear becomes muffled**, mono and flat, like a phone call from 2005.

That's not your AirPods and not a setting you missed. With classic Bluetooth, Windows can only use the AirPods mic through the **Hands-Free profile**: 16 kHz, mono, everything above about 8 kHz cut off. Game audio, music and voices all go through it as long as the mic is open.

The usual "fixes" just trade one problem for another: disable Hands-Free and you lose the mic, or buy a separate mic.

## The fix

ClearPods talks to your AirPods the way an iPhone does. Your AirPods mic comes in over Apple's own channel (AAC-ELD, 64 kHz) while **your sound stays in full-quality stereo**. Windows sees a new microphone, **"Headset (A2DP, &lt;your AirPods&gt;)"**: pick it in Discord, your game or any app.

- 🎧 **Stereo sound while you talk.** No more muffled audio in game chat.
- 🎙️ **Your AirPods mic, clearer than Hands-Free**, with optional noise suppression that runs on your PC.
- 🔋 **Mic really off when nobody uses it**, so your AirPods don't drain faster, and **both buds keep playing** when it turns off (see [what's new](#whats-new-in-clearpods)).
- 🎛️ **AirPods controls on Windows:** battery, noise control (Off, Transparency, Adaptive, Noise Cancellation), ear detection, conversation awareness, press-and-hold settings and more.
- 🪟 **Built for Windows 11:** tray icon, light and dark theme, hotkeys, 45 languages.

## What's new in ClearPods

- **Both buds keep playing after the mic stops.** Stopping the AirPods mic left them playing from one bud only until you reconnected them. ClearPods now restarts the audio stream right after the mic stops (about 0.4 s gap), and both buds come back.
- **New look:** light, airy design with a teal accent, new icon.
- **Updates are opt-in.** Nothing replaces your install without you choosing it.

## Install

**Requirements:** Windows 11 (x64), administrator rights, a built-in or USB Bluetooth adapter.

1. **Download** `ClearPods-Setup.exe` from the [latest release](https://github.com/Yukouf/ClearPods/releases/latest).
2. **Run it** and accept the terms. They explain the Bluetooth adapter takeover (see [How it works](#how-it-works)).
3. **Open ClearPods**, open your AirPods case near your PC and click **Connect**.
4. In ClearPods' **Windows settings**, turn on **Disable Hands-Free mode**.
5. In Discord (Settings > Voice & Video > Input device) or your game, pick **"Headset (A2DP, &lt;your AirPods&gt;)"**.

**Tested on:** AirPods Pro with an Intel Wi-Fi 6E AX211 adapter (USB ID `8087:0033`). Other AirPods and adapters should work but haven't been tested yet. If you try one, please [open an issue](https://github.com/Yukouf/ClearPods/issues) and say how it went, even if everything works.

**Uninstall:** Windows Settings > Apps > Installed apps > ClearPods > Uninstall. Your Bluetooth adapter goes back to Windows' own driver.

## How it works

Windows' Bluetooth stack can't give you the AirPods mic without switching them to Hands-Free. So ClearPods steps in between Windows and your Bluetooth adapter:

1. A background service takes over the adapter with WinUSB (built into Windows) and gives it back to Windows as a **virtual adapter** through [usbip-win2](https://github.com/vadimgrn/usbip-win2) (Microsoft-signed drivers). Your other Bluetooth devices keep working.
2. It opens Apple's accessory channel to your AirPods, asks for the mic, decodes the AAC-ELD stream and plays it into a virtual microphone.
3. It turns down Windows' Hands-Free requests, so your AirPods stay in stereo.
4. When the mic stops, it suspends and restarts the AirPods' audio stream so both buds keep playing.

Everything runs locally. The only thing ClearPods does online is check this repository's releases for a new version. The adapter takeover is reversible: uninstalling gives the adapter back to Windows, and so does a takeover that fails 3 times in 10 minutes. **Use at your own risk; ClearPods comes with no warranty.**

## FAQ

**Is there a delay?** Bluetooth always adds a little latency. In our tests ClearPods doesn't add a noticeable delay. Turn on **Low audio latency** in ClearPods' Windows settings if you want the mic and sound to be ready instantly (uses a bit more battery).

**Discord doesn't hear me.** Pick "Headset (A2DP, &lt;your AirPods&gt;)" as Discord's input device. After reinstalling ClearPods, pick it again: Windows gives the mic a new ID.

**No sound after putting my AirPods back in.** Windows sometimes reconnects them without audio. Open Bluetooth settings, click your AirPods > Disconnect, then Connect.

**Where are the logs?** `C:\ProgramData\ClearPods\logs` (service) and `%LOCALAPPDATA%\ClearPods\logs` (app). Zip both and attach them to your issue. They contain device names and Bluetooth addresses, never pairing keys or audio.

## Help and feedback

Found a bug or have an idea? [Open an issue](https://github.com/Yukouf/ClearPods/issues).

## License and credits

ClearPods is free software under the [GPL-3.0](LICENSE) license. It is based on [WPods](https://github.com/FPNDev/wpods) by fpndev. Third-party components and their licenses are listed in [THIRD-PARTY-NOTICES.txt](THIRD-PARTY-NOTICES.txt).

ClearPods is not made, affiliated with, sponsored or endorsed by Apple Inc. Apple, AirPods, AirPods Pro, AirPods Max, iPhone and Mac are trademarks of Apple Inc., registered in the U.S. and other countries.
