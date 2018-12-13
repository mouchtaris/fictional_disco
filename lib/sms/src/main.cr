# vim: et ts=2 sw=2

require "./impls"
require "./cli"

struct Main
  include Actions
  include Cli

  def initialize(argv)
    sms_root = argv[0]
    @conf = ConfDirStorage.new(sms_root)
    @logger = Logging.logger_for "Main"

    if argv.size > 1
      command = argv[1]

      case command
      when /^\+h/
        log.info "Adding header"
        _, args = command.split(":", 2)
        add_header args
      when /^list_config/
        list_config
      else
        log.warn "Unknown #{command}"
      end
    end
  end

  def main
    generate_cmake
    generate_source_files
    generate_header_files
  end

  def self.main
    Main.new(ARGV.dup).main
  end
end

Main.main
