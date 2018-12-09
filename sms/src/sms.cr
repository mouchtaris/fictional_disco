# vim: et ts=2 sw=2

module Args
  def initialize(argv)
    @argv = argv || [] of String
    @argi = 0
  end

  def arg_shift
    if @argi >= @argv.size
      raise ArgumentError.new("Args done at #{@argi}")
    end
    @argv[@argi].tap do
      @argi += 1
    end
  end
end

module Sms
  VERSION = "0.1.0"
  include Args

  def dispatchoes
    {
      help: ->cli_help,
      new: ->cli_new,
    }
  end

  def news
    {
      fun: ->cli_new_fun
    }
  end

  def cli_dispatcho
    command = arg_shift
    dispatchoes[command].call
  end

  def cli_new
    wat = arg_shift
    news[wat].call
  end

  def cli_help
    puts "=== Commands ==="
    pp dispatchoes.keys
    puts ""
    puts "--- new ---"
    pp news.keys
  end

  def cli_new_fun
    ns = arg_shift
    name = arg_shift
    puts "#{ns}/src/#{name}"
  end
end

class Cli
  include Sms

  def initialize(*args)
    super
  end
end

cli = Cli.new(ARGV)
cli.cli_dispatcho
